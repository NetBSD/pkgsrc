$NetBSD: patch-js_src_config_rules.mk,v 1.2 2012/07/18 16:10:06 ryoon Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=736961

--- js/src/config/rules.mk.orig	2012-07-04 16:03:34.000000000 +0000
+++ js/src/config/rules.mk
@@ -1452,7 +1452,7 @@ $(XPIDL_GEN_DIR)/%.h: %.idl $(XPIDL_DEPS
 	$(PYTHON_PATH) \
 	  $(PLY_INCLUDE) \
 	  -I$(topsrcdir)/xpcom/idl-parser \
-	  $(topsrcdir)/xpcom/idl-parser/header.py --cachedir=$(DEPTH)/xpcom/idl-parser $(XPIDL_FLAGS) $(_VPATH_SRCS) -d $(MDDEPDIR)/$(@F).pp -o $@
+	  $(topsrcdir)/xpcom/idl-parser/header.py --cachedir=$(DEPTH)/xpcom/idl-parser/cache $(XPIDL_FLAGS) $(_VPATH_SRCS) -d $(MDDEPDIR)/$(@F).pp -o $@
 	@if test -n "$(findstring $*.h, $(EXPORTS))"; \
 	  then echo "*** WARNING: file $*.h generated from $*.idl overrides $(srcdir)/$*.h"; else true; fi
 
@@ -1465,7 +1465,7 @@ $(XPIDL_GEN_DIR)/%.xpt: %.idl $(XPIDL_DE
 	  $(PLY_INCLUDE) \
 	  -I$(topsrcdir)/xpcom/idl-parser \
 	  -I$(topsrcdir)/xpcom/typelib/xpt/tools \
-	  $(topsrcdir)/xpcom/idl-parser/typelib.py --cachedir=$(DEPTH)/xpcom/idl-parser $(XPIDL_FLAGS) $(_VPATH_SRCS) -d $(MDDEPDIR)/$(@F).pp -o $@
+	  $(topsrcdir)/xpcom/idl-parser/typelib.py --cachedir=$(DEPTH)/xpcom/idl-parser/cache $(XPIDL_FLAGS) $(_VPATH_SRCS) -d $(MDDEPDIR)/$(@F).pp -o $@
 
 # no need to link together if XPIDLSRCS contains only XPIDL_MODULE
 ifneq ($(XPIDL_MODULE).idl,$(strip $(XPIDLSRCS)))
