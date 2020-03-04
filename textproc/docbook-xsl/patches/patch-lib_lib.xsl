$NetBSD: patch-lib_lib.xsl,v 1.2 2020/03/04 10:11:40 wiz Exp $

Use EXSLT "replace" function when available.
https://bugs.debian.org/750593

--- lib/lib.xsl.orig	2016-12-09 22:41:39.000000000 +0000
+++ lib/lib.xsl
@@ -6,7 +6,10 @@
 
      This module implements DTD-independent functions
 
-     ******************************************************************** --><xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
+     ******************************************************************** --><xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
+                xmlns:str="http://exslt.org/strings"
+                exclude-result-prefixes="str"
+                version="1.0">
 
 <xsl:template name="dot.count">
   <!-- Returns the number of "." characters in a string -->
@@ -52,6 +55,9 @@
   <xsl:param name="replacement"/>
 
   <xsl:choose>
+    <xsl:when test="function-available('str:replace')">
+      <xsl:value-of select="str:replace($string, string($target), string($replacement))"/>
+    </xsl:when>
     <xsl:when test="contains($string, $target)">
       <xsl:variable name="rest">
         <xsl:call-template name="string.subst">
