$NetBSD: patch-gmodule_gmodule-dyld.c,v 1.1 2018/10/08 10:12:06 prlw1 Exp $

http://bugzilla.gnome.org/show_bug.cgi?id=107626
https://gitlab.gnome.org/GNOME/glib/issues/19

--- gmodule/gmodule-dyld.c.orig	2018-09-14 11:18:09.527026838 +0000
+++ gmodule/gmodule-dyld.c
@@ -96,8 +96,7 @@ _g_module_self (void)
 }
 
 static void
-_g_module_close (gpointer handle,
-		 gboolean is_unref)
+_g_module_close (gpointer handle)
 {
   if (handle == &self_module)
     return;
@@ -118,7 +117,13 @@ _g_module_symbol (gpointer     handle,
       if (NSIsSymbolNameDefined (symbol_name))
 	sym = NSLookupAndBindSymbol (symbol_name);
       else
-	sym = NULL;
+	{
+	  GModule *mod;
+	  for (mod = modules, sym = NULL; mod && !sym; mod = mod->next)
+	    {
+	      sym = NSLookupSymbolInModule (mod->handle, symbol_name);
+	    }
+	}
     }
   else
     sym = NSLookupSymbolInModule (handle, symbol_name);
