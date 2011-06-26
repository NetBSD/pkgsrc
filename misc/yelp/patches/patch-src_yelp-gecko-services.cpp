$NetBSD: patch-src_yelp-gecko-services.cpp,v 1.1 2011/06/26 12:46:06 obache Exp $

* xulrunner-2 support.

--- src/yelp-gecko-services.cpp.orig	2010-08-03 19:41:59.000000000 +0000
+++ src/yelp-gecko-services.cpp
@@ -32,7 +32,11 @@
 #include <nsIComponentManager.h>
 #include <nsComponentManagerUtils.h>
 #include <nsIComponentRegistrar.h>
+#ifndef HAVE_GECKO_2_0
 #include <nsIGenericFactory.h>
+#else
+#include <nsIFactory.h>
+#endif
 #include <nsILocalFile.h>
 #include <nsIPrintSettings.h>
 #include <nsServiceManagerUtils.h>
@@ -418,6 +422,8 @@ PrintListener::SetPrintSettings (YelpPri
 
 /* component registration */
 
+#ifndef HAVE_GECKO_2_0
+
 NS_GENERIC_FACTORY_CONSTRUCTOR(GPrintingPromptService)
 
 static const nsModuleComponentInfo sAppComps[] = {
@@ -462,3 +468,115 @@ yelp_register_printing ()
     }
     
 }
+
+#else
+
+/*
+ * Adapted from code from ./embedding/browser/activex/src/control/PromptService.cpp in Firefox
+ */
+
+//*****************************************************************************
+// GPrintingPromptServiceFactory
+//*****************************************************************************
+
+class GPrintingPromptServiceFactory : public nsIFactory
+{
+public:
+    NS_DECL_ISUPPORTS
+    NS_DECL_NSIFACTORY
+
+    GPrintingPromptServiceFactory();
+    virtual ~GPrintingPromptServiceFactory();
+};
+
+//*****************************************************************************
+
+NS_IMPL_ISUPPORTS1(GPrintingPromptServiceFactory, nsIFactory)
+
+GPrintingPromptServiceFactory::GPrintingPromptServiceFactory()
+{
+}
+
+GPrintingPromptServiceFactory::~GPrintingPromptServiceFactory()
+{
+}
+
+NS_IMETHODIMP GPrintingPromptServiceFactory::CreateInstance(nsISupports *aOuter, const nsIID & aIID, void **aResult)
+{
+    NS_ENSURE_ARG_POINTER(aResult);
+
+    *aResult = NULL;
+    GPrintingPromptService *inst = new GPrintingPromptService;
+    if (!inst)
+    return NS_ERROR_OUT_OF_MEMORY;
+
+    nsresult rv = inst->QueryInterface(aIID, aResult);
+    if (rv != NS_OK) {
+        // We didn't get the right interface, so clean up
+        delete inst;
+    }
+
+    return rv;
+}
+
+NS_IMETHODIMP GPrintingPromptServiceFactory::LockFactory(PRBool lock)
+{
+    return NS_OK;
+}
+
+//*****************************************************************************
+
+nsresult NS_NewPrintingPromptServiceFactory(nsIFactory** aFactory)
+{
+    NS_ENSURE_ARG_POINTER(aFactory);
+    *aFactory = nsnull;
+
+    GPrintingPromptServiceFactory *result = new GPrintingPromptServiceFactory;
+    if (!result)
+        return NS_ERROR_OUT_OF_MEMORY;
+
+    NS_ADDREF(result);
+    *aFactory = result;
+
+    return NS_OK;
+}
+
+/*
+ * End of adapted code.
+ */
+
+static NS_DEFINE_CID(kGPrintingPromptServiceCID, G_PRINTINGPROMPTSERVICE_CID);
+
+void
+yelp_register_printing ()
+{
+  nsresult rv;
+  nsCOMPtr<nsIComponentRegistrar> cr;
+  rv = NS_GetComponentRegistrar(getter_AddRefs(cr));
+  NS_ENSURE_SUCCESS (rv, );
+
+  nsCOMPtr<nsIComponentManager> cm;
+  rv = NS_GetComponentManager (getter_AddRefs (cm));
+  NS_ENSURE_SUCCESS (rv, );
+
+  nsCOMPtr<nsIFactory> componentFactory;
+  rv = NS_NewPrintingPromptServiceFactory(getter_AddRefs(componentFactory));
+
+  if (NS_FAILED(rv) || !componentFactory)
+    {
+      g_warning ("Failed to make a factory for %s\n", G_PRINTINGPROMPTSERVICE_CLASSNAME);
+      return;
+    }
+
+  rv = cr->RegisterFactory(kGPrintingPromptServiceCID,
+			   G_PRINTINGPROMPTSERVICE_CLASSNAME,
+			   G_PRINTINGPROMPTSERVICE_CONTRACTID,
+			   componentFactory);
+  if (NS_FAILED(rv))
+    {
+      g_warning ("Failed to register %s\n", G_PRINTINGPROMPTSERVICE_CLASSNAME);
+    }
+
+}
+
+#endif
