https://bugzilla.mozilla.org/show_bug.cgi?id=637437

--- js/src/jsdbgapi.cpp	
+++ js/src/jsdbgapi.cpp	
@@ -111,28 +111,26 @@ JS_SetRuntimeDebugMode(JSRuntime *rt, JS
 {
     rt->debugMode = debug;
 }
 
 #ifdef DEBUG
 static bool
 CompartmentHasLiveScripts(JSCompartment *comp)
 {
-#ifdef JS_METHODJIT
-# ifdef JS_THREADSAFE
+#if defined(JS_METHODJIT) && defined(JS_THREADSAFE)
     jsword currentThreadId = reinterpret_cast<jsword>(js_CurrentThreadId());
-# endif
 #endif
 
     // Unsynchronized context iteration is technically a race; but this is only
     // for debug asserts where such a race would be rare
     JSContext *iter = NULL;
     JSContext *icx;
     while ((icx = JS_ContextIterator(comp->rt, &iter))) {
-#ifdef JS_THREADSAFE
+#if defined(JS_METHODJIT) && defined(JS_THREADSAFE)
         if (JS_GetContextThread(icx) != currentThreadId)
             continue;
 #endif
         for (AllFramesIter i(icx); !i.done(); ++i) {
             JSScript *script = i.fp()->maybeScript();
             if (script && script->compartment == comp)
                 return JS_TRUE;
         }
