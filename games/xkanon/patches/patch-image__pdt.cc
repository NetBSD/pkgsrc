$NetBSD: patch-image__pdt.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Appease LP64 warnings.

--- image_pdt.cc.orig	2008-01-06 06:20:00.000000000 +0000
+++ image_pdt.cc
@@ -341,7 +341,7 @@ PDT_Reader::~PDT_Reader() {
 	DI_ImageMaskPDT::PTHREAD_LOG_EXTERNAL("delete PDT reader\n");
 	while(head_cache) {
 		PDT_Item* next = head_cache->NextItem();
-		DI_ImageMaskPDT::PTHREAD_LOG_EXTERNAL("delete PDT cache %08x\n",int(head_cache));
+		DI_ImageMaskPDT::PTHREAD_LOG_EXTERNAL("delete PDT cache %08lx\n",long(head_cache));
 		delete head_cache;
 		head_cache = next;
 	}
@@ -379,7 +379,7 @@ PDT_Item::PDT_Item(char* path, int h, Ay
 
 PDT_Item::~PDT_Item() {
 	if (image) {
-		DI_ImageMaskPDT::PTHREAD_LOG_EXTERNAL("delete PDT item; %08x\n",int(image));
+		DI_ImageMaskPDT::PTHREAD_LOG_EXTERNAL("delete PDT item; %08lx\n",long(image));
 		if (dynamic_cast<DI_ImageMaskPDT*>(image)) {
 			dynamic_cast<DI_ImageMaskPDT*>(image)->WaitForReading(); // thread を終了させる
 		}
