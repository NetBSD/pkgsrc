$NetBSD: patch-pygi_info.c,v 1.1 2012/02/10 15:54:05 drochner Exp $

GI_INFO_TYPE_ERROR_DOMAIN is deprecated as "The previous ErrorDomain
blob was never actually scanned or used, and it was kind of a lame
API conceptually."

This will give a harmless
  warning: enumeration value 'GI_INFO_TYPE_ERROR_DOMAIN' not handled in switch
for those who still have it, but allow py-gobject to build for those who
don't.

--- gi/pygi-info.c.orig	2011-06-13 16:30:25.000000000 +0000
+++ gi/pygi-info.c
@@ -162,9 +162,6 @@ _pygi_info_new (GIBaseInfo *info)
         case GI_INFO_TYPE_CONSTANT:
             type = &PyGIConstantInfo_Type;
             break;
-        case GI_INFO_TYPE_ERROR_DOMAIN:
-            type = &PyGIErrorDomainInfo_Type;
-            break;
         case GI_INFO_TYPE_UNION:
             type = &PyGIUnionInfo_Type;
             break;
@@ -481,7 +478,6 @@ _pygi_g_type_info_size (GITypeInfo *type
                 case GI_INFO_TYPE_INVALID:
                 case GI_INFO_TYPE_FUNCTION:
                 case GI_INFO_TYPE_CONSTANT:
-                case GI_INFO_TYPE_ERROR_DOMAIN:
                 case GI_INFO_TYPE_VALUE:
                 case GI_INFO_TYPE_SIGNAL:
                 case GI_INFO_TYPE_PROPERTY:
@@ -860,7 +856,6 @@ pygi_g_struct_info_is_simple (GIStructIn
                     case GI_INFO_TYPE_INVALID:
                     case GI_INFO_TYPE_FUNCTION:
                     case GI_INFO_TYPE_CONSTANT:
-                    case GI_INFO_TYPE_ERROR_DOMAIN:
                     case GI_INFO_TYPE_VALUE:
                     case GI_INFO_TYPE_SIGNAL:
                     case GI_INFO_TYPE_PROPERTY:
