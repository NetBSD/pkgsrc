$NetBSD: patch-include_solarus_EntityData.h,v 1.1 2015/07/07 11:41:19 joerg Exp $

With the constt, EntityData::EntityField is not copy-assignable, but
that is required elsewhere for use by .insert().

--- include/solarus/EntityData.h.orig	2015-07-04 14:10:49.000000000 +0000
+++ include/solarus/EntityData.h
@@ -63,7 +63,7 @@ class SOLARUS_API EntityData : public Lu
         bool operator==(const FieldValue& other) const;
         bool operator!=(const FieldValue& other) const;
 
-        const EntityFieldType value_type;
+        EntityFieldType value_type;
         std::string string_value;
         int int_value;  // Also used for boolean.
     };
