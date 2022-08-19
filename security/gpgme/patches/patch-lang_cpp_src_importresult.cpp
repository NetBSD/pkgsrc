$NetBSD: patch-lang_cpp_src_importresult.cpp,v 1.1 2022/08/19 11:15:16 tnn Exp $

Fix building with C++ 11
https://dev.gnupg.org/T6141

--- lang/cpp/src/importresult.cpp.orig	2022-08-10 09:17:33.000000000 +0000
+++ lang/cpp/src/importresult.cpp
@@ -152,17 +152,17 @@ void GpgME::ImportResult::mergeWith(cons
         }
         // was this key also considered during the first import
         const auto consideredInFirstImports =
-            std::any_of(std::begin(d->imports), std::end(d->imports), [fpr](const auto i) {
+            std::any_of(std::begin(d->imports), std::end(d->imports), [fpr](const gpgme_import_status_t i) {
                 return i->fpr && !strcmp(i->fpr, fpr);
             });
         // did we see this key already in the list of keys of the other import
         const auto consideredInPreviousOtherImports =
-            std::any_of(std::begin(other.d->imports), it, [fpr](const auto i) {
+            std::any_of(std::begin(other.d->imports), it, [fpr](const gpgme_import_status_t i) {
                 return i->fpr && !strcmp(i->fpr, fpr);
             });
         // was anything added to this key during the other import
         const auto changedInOtherImports =
-            std::any_of(std::begin(other.d->imports), std::end(other.d->imports), [fpr](const auto i) {
+            std::any_of(std::begin(other.d->imports), std::end(other.d->imports), [fpr](const gpgme_import_status_t i) {
                 return i->fpr && !strcmp(i->fpr, fpr) && (i->status != 0);
             });
         if (consideredInFirstImports && !consideredInPreviousOtherImports) {
@@ -177,15 +177,15 @@ void GpgME::ImportResult::mergeWith(cons
 
         // now do the same for the secret key counts
         const auto secretKeyConsideredInFirstImports =
-            std::any_of(std::begin(d->imports), std::end(d->imports), [fpr](const auto i) {
+            std::any_of(std::begin(d->imports), std::end(d->imports), [fpr](const gpgme_import_status_t i) {
                 return i->fpr && !strcmp(i->fpr, fpr) && (i->status & GPGME_IMPORT_SECRET);
             });
         const auto secretKeyConsideredInPreviousOtherImports =
-            std::any_of(std::begin(other.d->imports), it, [fpr](const auto i) {
+            std::any_of(std::begin(other.d->imports), it, [fpr](const gpgme_import_status_t i) {
                 return i->fpr && !strcmp(i->fpr, fpr) && (i->status & GPGME_IMPORT_SECRET);
             });
         const auto secretKeyChangedInOtherImports =
-            std::any_of(std::begin(other.d->imports), std::end(other.d->imports), [fpr](const auto i) {
+            std::any_of(std::begin(other.d->imports), std::end(other.d->imports), [fpr](const gpgme_import_status_t i) {
                 return i->fpr && !strcmp(i->fpr, fpr) && (i->status & GPGME_IMPORT_SECRET) && (i->status != GPGME_IMPORT_SECRET);
             });
         if (secretKeyConsideredInFirstImports && !secretKeyConsideredInPreviousOtherImports) {
@@ -204,7 +204,7 @@ void GpgME::ImportResult::mergeWith(cons
     d->imports.reserve(d->imports.size() + other.d->imports.size());
     std::transform(std::begin(other.d->imports), std::end(other.d->imports),
                    std::back_inserter(d->imports),
-                   [](const auto import) {
+                   [](const gpgme_import_status_t import) {
                        gpgme_import_status_t copy = new _gpgme_import_status{*import};
                        if (import->fpr) {
                            copy->fpr = strdup(import->fpr);
