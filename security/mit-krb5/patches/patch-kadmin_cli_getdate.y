$NetBSD: patch-kadmin_cli_getdate.y,v 1.1 2021/01/16 09:00:23 jperkin Exp $

Backport upstream fix https://github.com/krb5/krb5/commit/d3356bc4

--- kadmin/cli/getdate.y.orig	2020-11-17 17:17:59.000000000 +0000
+++ kadmin/cli/getdate.y
@@ -185,12 +185,10 @@ static time_t	yyRelSeconds;
     enum _MERIDIAN	Meridian;
 }
 
-%token	tAGO tDAY tDAYZONE tID tMERIDIAN tMINUTE_UNIT tMONTH tMONTH_UNIT
-%token	tSEC_UNIT tSNUMBER tUNUMBER tZONE tDST tNEVER
-
-%type	<Number>	tDAY tDAYZONE tMINUTE_UNIT tMONTH tMONTH_UNIT
-%type	<Number>	tSEC_UNIT tSNUMBER tUNUMBER tZONE
-%type	<Meridian>	tMERIDIAN o_merid
+%token			tAGO tID tDST tNEVER
+%token	<Number>	tDAY tDAYZONE tMINUTE_UNIT tMONTH tMONTH_UNIT
+%token	<Number>	tSEC_UNIT tSNUMBER tUNUMBER tZONE tMERIDIAN
+%type	<Meridian>	o_merid
 
 %%
 
