$NetBSD: patch-sim_ucsim_cmd.src_cmdlex.cc,v 1.1 2012/01/24 06:06:32 sbd Exp $

Include <cstdio> for the EOF macro.

--- sim/ucsim/cmd.src/cmdlex.cc.orig	2004-07-16 16:32:30.000000000 +0000
+++ sim/ucsim/cmd.src/cmdlex.cc
@@ -409,6 +409,7 @@ static yyconst flex_int16_t yy_chk[56] =
 #line 2 "cmdlex.l"
 #include "cmdlexcl.h"
 #include "cmdpars.h"
+#include <cstdio>
 
 static YY_cl_ucsim_parser_STYPE *yylval;
 
