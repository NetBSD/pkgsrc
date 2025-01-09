$NetBSD: patch-termcap.c,v 1.1 2025/01/09 20:07:04 ktnb Exp $

Don't pollute G1 to allow 8-bit encondings.

The original code made the TERMCAP env var longer than 1023 bytes,
which causes problems.  This is a quick hack but works with our termcap.

--- termcap.c.orig	2025-01-09 02:57:57.777207358 +0000
+++ termcap.c
@@ -65,7 +65,7 @@ char *extra_incap, *extra_outcap;
 static const char TermcapConst[] = "DO=\\E[%dB:LE=\\E[%dD:RI=\\E[%dC:\
 UP=\\E[%dA:bs:bt=\\E[Z:cd=\\E[J:ce=\\E[K:cl=\\E[H\\E[J:cm=\\E[%i%d;%dH:\
 ct=\\E[3g:do=^J:nd=\\E[C:pt:rc=\\E8:rs=\\Ec:sc=\\E7:st=\\EH:up=\\EM:\
-le=^H:bl=^G:cr=^M:it#8:ho=\\E[H:nw=\\EE:ta=^I:is=\\E)0:";
+le=^H:bl=^G:cr=^M:it#8:ho=\\E[H:nw=\\EE:ta=^I:is=\\E(B:";
 
 char *gettermcapstring(char *s)
 {
