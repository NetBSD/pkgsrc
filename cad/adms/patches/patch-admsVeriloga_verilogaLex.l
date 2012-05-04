$NetBSD: patch-admsVeriloga_verilogaLex.l,v 1.1 2012/05/04 16:03:13 joerg Exp $

--- admsVeriloga/verilogaLex.l.orig	2012-04-28 21:40:07.000000000 +0000
+++ admsVeriloga/verilogaLex.l
@@ -33,14 +33,14 @@ void adms_veriloga_error (const char *s)
   adms_message_fatal(("%s: during lexical analysis %s at line %i -- see '%s'\n",
     adms_admsmain_valueof_filename(adms_global_admsmain())->_value,s,adms_admsmain_valueof_curline(adms_global_admsmain ()),adms_veriloga_text))
 }
-inline void POS_UPDATE(const int myyyleng,const char*myyytext)
+static inline void POS_UPDATE(const int myyyleng,const char*myyytext)
 {
   int fpos=adms_admsmain_valueof_fpos(adms_global_admsmain());
   adms_message_dbg_vla(("%s:%i:%i-%i read token '%s'\n",adms_admsmain_valueof_filename(adms_global_admsmain())->_value,
     adms_admsmain_valueof_curline(adms_global_admsmain()),fpos+1,fpos+myyyleng,myyytext))
   adms_admsmain_valueto_fpos(adms_global_admsmain(),fpos+myyyleng);
 }
-inline void TKRETURN(const char*myyytext, const int myyyleng)
+static inline void TKRETURN(const char*myyytext, const int myyyleng)
 {
   POS_UPDATE(myyyleng,myyytext);
   adms_veriloga_lval._lexval=adms_lexval_new(
@@ -50,7 +50,7 @@ inline void TKRETURN(const char*myyytext
     adms_admsmain_valueof_fpos(adms_global_admsmain())
   );
 }
-inline void TKSTRIPPEDRETURN(const char*myyytext, const int myyyleng)
+static inline void TKSTRIPPEDRETURN(const char*myyytext, const int myyyleng)
 {
   char*mystrippedstring;
   int mynewlen=strlen(myyytext)-2;
