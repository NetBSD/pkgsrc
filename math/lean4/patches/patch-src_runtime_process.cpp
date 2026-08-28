$NetBSD: patch-src_runtime_process.cpp,v 1.3 2026/08/28 18:35:12 wiz Exp $

Set proper thread id on NetBSD.
clearenv() does not exist on NetBSD.
https://github.com/leanprover/lean4/pull/14543

Create environment before forking
https://github.com/leanprover/lean4/issues/14587

--- src/runtime/process.cpp.orig	2026-08-15 19:18:21.000000000 +0000
+++ src/runtime/process.cpp
@@ -8,7 +8,9 @@ Author: Jared Roesch
 #include <fstream>
 #include <iostream>
 #include <iomanip>
+#include <map>
 #include <utility>
+#include <vector>
 #include <system_error>
 
 #if defined(LEAN_WINDOWS)
@@ -341,6 +343,8 @@ extern "C" LEAN_EXPORT uint64_t lean_io_get_tid() {
     uint64_t tid;
 #ifdef __APPLE__
     lean_always_assert(pthread_threadid_np(NULL, &tid) == 0);
+#elif defined(__NetBSD__)
+    tid = (uint64_t)pthread_self();
 #elif defined(LEAN_EMSCRIPTEN)
     tid = 0;
 #else
@@ -431,10 +435,52 @@ static optional<pipe> setup_stdio(stdio cfg) {
     lean_unreachable();
 }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
 extern "C" char **environ;
 #endif
 
+static std::vector<char*> build_environ(bool inherit_env, array_ref<pair_ref<string_ref, option_ref<string_ref>>> const & env) {
+    std::map<std::string, std::string> current;
+    if (inherit_env) {
+	/* Build a lookup map from current environ */
+	for (char** env = environ; *env; ++env) {
+	    auto sep = std::strstr(*env, "=");
+	    if (sep) {
+		std::string key(*env, sep - *env);
+		current[std::move(key)] = sep + 1;
+	    }
+	}
+    }
+
+    /* Apply overrides */
+    for (auto & entry : env) {
+	if (entry.snd()) {
+	    current[entry.fst().data()] = entry.snd().get()->data();
+	} else {
+	    current.erase(entry.fst().data());
+	}
+    }
+
+    /* Create the new environ array */
+    std::vector<char*> result;
+    result.reserve(current.size() + 1);
+
+    for (auto & [key, val] : current) {
+        size_t key_len = key.size();
+        size_t val_len = val.size();
+        size_t total = key_len + 1 + val_len + 1;
+        char* entry = new char[total];
+        std::memcpy(entry, key.data(), key_len);
+        entry[key_len] = '=';
+        std::memcpy(entry + key_len + 1, val.data(), val_len);
+        entry[key_len + 1 + val_len] = '\0';
+        result.push_back(entry);
+    }
+
+    result.push_back(nullptr);
+    return result;
+}
+
 static obj_res spawn(string_ref const & proc_name, array_ref<string_ref> const & args, stdio stdin_mode, stdio stdout_mode,
   stdio stderr_mode, option_ref<string_ref> const & cwd, array_ref<pair_ref<string_ref, option_ref<string_ref>>> const & env,
   bool inherit_env, bool do_setsid) {
@@ -450,24 +496,11 @@ static obj_res spawn(string_ref const & proc_name, arr
         pargs.push_back(strdup(arg.data()));
     pargs.push_back(NULL);
 
+    std::vector<char*> new_env =  build_environ(inherit_env, env);
+
     int pid = fork();
 
     if (pid == 0) {
-        if (!inherit_env) {
-#ifdef __APPLE__
-            environ = NULL;
-#else
-            clearenv();
-#endif
-        }
-        for (auto & entry : env) {
-            if (entry.snd()) {
-                setenv(entry.fst().data(), entry.snd().get()->data(), true);
-            } else {
-                unsetenv(entry.fst().data());
-            }
-        }
-
         if (stdin_pipe) {
             dup2(stdin_pipe->m_read_fd, STDIN_FILENO);
             close(stdin_pipe->m_write_fd);
@@ -507,7 +540,7 @@ static obj_res spawn(string_ref const & proc_name, arr
             lean_always_assert(setsid() >= 0);
         }
 
-        if (execvp(pargs[0], pargs.data()) < 0) {
+        if (execvpe(pargs[0], pargs.data(), new_env.data()) < 0) {
             std::cerr << "could not execute external process '" << pargs[0] << "'" << std::endl;
             // See the comment above about `_exit` vs `exit`.
             _exit(-1);
@@ -520,6 +553,11 @@ static obj_res spawn(string_ref const & proc_name, arr
         if (parg != NULL) {
             free(parg);
         }
+    }
+    for (char* entry : new_env) {
+        if (entry != NULL) {
+	    free(entry);
+	}
     }
 
     object * parent_stdin  = box(0);
