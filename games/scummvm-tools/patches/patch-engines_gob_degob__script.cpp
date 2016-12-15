$NetBSD: patch-engines_gob_degob__script.cpp,v 1.1 2016/12/15 23:53:38 joerg Exp $

--- engines/gob/degob_script.cpp.orig	2016-12-15 16:41:44.458856760 +0000
+++ engines/gob/degob_script.cpp
@@ -182,7 +182,7 @@ byte *ExtTable::unpack(const byte *packe
 Script::Script(byte *totData, uint32 totSize, ExtTable *extTable) :
 	_totData(totData), _ptr(totData), _totSize(totSize), _extTable(extTable) {
 
-	assert((totData > 0) && (totSize > 128));
+	assert(totData && (totSize > 128));
 
 	_indent = 0;
 
