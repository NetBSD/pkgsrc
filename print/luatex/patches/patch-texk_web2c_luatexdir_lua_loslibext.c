$NetBSD: patch-texk_web2c_luatexdir_lua_loslibext.c,v 1.1 2023/05/24 12:03:35 markd Exp $

1.16.0 -> 1.17.0

--- texk/web2c/luatexdir/lua/loslibext.c	2023/05/01 23:50:21	66983
+++ texk/web2c/luatexdir/lua/loslibext.c	2023/05/02 15:26:43	66984
@@ -1047,6 +1047,167 @@ static int os_execute(lua_State * L)
 }
 
 
+/*
+** ======================================================
+** l_kpse_popen spawns a new process connected to the current
+** one through the file streams with some checks by kpse.
+** Almost verbatim from Lua liolib.c .
+** =======================================================
+*/
+#if !defined(l_kpse_popen)           /* { */
+
+#if defined(LUA_USE_POSIX)      /* { */
+
+#define l_kpse_popen(L,c,m)          (fflush(NULL), popen(c,m))
+#define l_kpse_pclose(L,file)        (pclose(file))
+
+#elif defined(LUA_USE_WINDOWS)  /* }{ */
+
+#define l_kpse_popen(L,c,m)          (_popen(c,m))
+#define l_kpse_pclose(L,file)        (_pclose(file))
+
+#else                           /* }{ */
+
+/* ISO C definitions */
+#define l_kpse_popen(L,c,m)  \
+          ((void)((void)c, m), \
+          luaL_error(L, "'popen' not supported"), \
+          (FILE*)0)
+#define l_kpse_pclose(L,file)                ((void)L, (void)file, -1)
+
+#endif                          /* } */
+
+#endif                          /* } */
+typedef luaL_Stream LStream;
+#define tolstream(L)    ((LStream *)luaL_checkudata(L, 1, LUA_FILEHANDLE))
+static LStream *newprefile (lua_State *L) {
+  LStream *p = (LStream *)lua_newuserdata(L, sizeof(LStream));
+  p->closef = NULL;  /* mark file handle as 'closed' */
+  luaL_setmetatable(L, LUA_FILEHANDLE);
+  return p;
+}
+static int io_kpse_pclose (lua_State *L) {
+  LStream *p = tolstream(L);
+  return luaL_execresult(L, l_kpse_pclose(L, p->f));
+}
+static int io_kpse_check_permissions(lua_State *L) {
+    const char *filename = luaL_checkstring(L, 1);
+    if (filename == NULL) {
+        lua_pushboolean(L,0);
+        lua_pushliteral(L,"no command name given");
+    } else if (shellenabledp <= 0) {
+        lua_pushboolean(L,0);
+        lua_pushliteral(L,"all command execution is disabled");
+    } else if (restrictedshell == 0) {
+        lua_pushboolean(L,1);
+        lua_pushstring(L,filename);
+    } else {
+        char *safecmd = NULL;
+        char *cmdname = NULL;
+        switch (shell_cmd_is_allowed(filename, &safecmd, &cmdname)) {
+            case 0:
+                lua_pushboolean(L,0);
+                lua_pushliteral(L, "specific command execution disabled");
+                break;
+            case 1:
+                /* doesn't happen */
+                lua_pushboolean(L,1);
+                lua_pushstring(L,filename);
+                break;
+            case 2:
+                lua_pushboolean(L,1);
+                lua_pushstring(L,safecmd);
+                break;
+            default:
+                /* -1 */
+                lua_pushboolean(L,0);
+                lua_pushliteral(L, "bad command line quoting");
+                break;
+        }
+    }
+    return 2;
+}
+static int io_kpse_popen (lua_State *L) {
+  const char *filename = NULL;
+  const char *mode = NULL;
+  LStream *p = NULL;
+  int okay;
+  filename = luaL_checkstring(L, 1);
+  mode = luaL_optstring(L, 2, "r");
+  lua_pushstring(L,filename);
+  io_kpse_check_permissions(L);
+  filename = luaL_checkstring(L, -1);
+  okay = lua_toboolean(L,-2);
+  if (okay && filename) {
+    p = newprefile(L);
+    luaL_argcheck(L, ((mode[0] == 'r' || mode[0] == 'w') && mode[1] == '\0'),
+		  2, "invalid mode");
+    p->f = l_kpse_popen(L, filename, mode);
+    p->closef = &io_kpse_pclose;
+    return (p->f == NULL) ? luaL_fileresult(L, 0, filename) : 1;
+  } else {
+    lua_pushnil(L);
+    lua_pushvalue(L,-2);
+    return 2;
+  }
+}
+
+
+
+/* socket.sleep and socket.gettime      */
+/* are duplicated here, and they are    */
+/* always available (the socket library */
+/* can  be nil in some setups)          */
+#ifdef _WIN32
+static int socket_timeout_lua_sleep(lua_State *L)
+{
+    double n = luaL_checknumber(L, 1);
+    if (n < 0.0) n = 0.0;
+    if (n < DBL_MAX/1000.0) n *= 1000.0;
+    if (n > INT_MAX) n = INT_MAX;
+    Sleep((int)n);
+    return 0;
+}
+static double socket_timeout_gettime(void) {
+    FILETIME ft;
+    double t;
+    GetSystemTimeAsFileTime(&ft);
+    /* Windows file time (time since January 1, 1601 (UTC)) */
+    t  = ft.dwLowDateTime/1.0e7 + ft.dwHighDateTime*(4294967296.0/1.0e7);
+    /* convert to Unix Epoch time (time since January 1, 1970 (UTC)) */
+    return (t - 11644473600.0);
+}
+#else
+static int socket_timeout_lua_sleep(lua_State *L)
+{
+    double n = luaL_checknumber(L, 1);
+    struct timespec t, r;
+    if (n < 0.0) n = 0.0;
+    if (n > INT_MAX) n = INT_MAX;
+    t.tv_sec = (int) n;
+    n -= t.tv_sec;
+    t.tv_nsec = (int) (n * 1000000000);
+    if (t.tv_nsec >= 1000000000) t.tv_nsec = 999999999;
+    while (nanosleep(&t, &r) != 0) {
+        t.tv_sec = r.tv_sec;
+        t.tv_nsec = r.tv_nsec;
+    }
+    return 0;
+}
+static double socket_timeout_gettime(void) {
+    struct timeval v;
+    gettimeofday(&v, (struct timezone *) NULL);
+    /* Unix Epoch time (time since January 1, 1970 (UTC)) */
+    return v.tv_sec + v.tv_usec/1.0e6;
+}
+#endif
+static int socket_timeout_lua_gettime(lua_State *L)
+{
+    lua_pushnumber(L, socket_timeout_gettime());
+    return 1;
+}
+
+
 void open_oslibext(lua_State * L)
 {
 
@@ -1081,5 +1242,15 @@ void open_oslibext(lua_State * L)
     lua_pushcfunction(L, os_tmpdir);
     lua_setfield(L, -2, "tmpdir");
 
+    lua_pushcfunction(L, io_kpse_popen);
+    lua_setfield(L, -2, "kpsepopen");
+
+    lua_pushcfunction(L, socket_timeout_lua_sleep);
+    lua_setfield(L, -2, "socketsleep");
+
+    lua_pushcfunction(L, socket_timeout_lua_gettime);
+    lua_setfield(L, -2, "socketgettime");
+
+
     lua_pop(L, 1);              /* pop the table */
 }
