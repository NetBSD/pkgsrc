$NetBSD: patch-rpcc_genheader.C,v 1.1 2013/10/15 14:48:38 joerg Exp $

--- rpcc/genheader.C.orig	2013-10-14 21:19:36.000000000 +0000
+++ rpcc/genheader.C
@@ -32,7 +32,7 @@ pmshl (str id)
 }
 
 static str
-decltype (const rpc_decl *d)
+my_decltype (const rpc_decl *d)
 {
   if (d->type == "string")
     return strbuf () << "rpc_str<" << d->bound << ">";
@@ -71,7 +71,7 @@ static void
 pdecl (str prefix, const rpc_decl *d)
 {
   str name = d->id;
-  aout << prefix << decltype (d) << " " << name << ";\n";
+  aout << prefix << my_decltype (d) << " " << name << ";\n";
 }
 
 static void
@@ -194,7 +194,7 @@ dumpunion (const rpc_sym *s)
     if (!rt->swval)
       hasdefault = true;
     if (rt->tagvalid && rt->tag.type != "void") {
-      str type = decltype (&rt->tag);
+      str type = my_decltype (&rt->tag);
       if (type[type.len ()-1] == '>')
 	type = type << " ";
       aout << "    union_entry<" << type << "> "
