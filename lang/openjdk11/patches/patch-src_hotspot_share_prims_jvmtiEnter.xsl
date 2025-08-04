$NetBSD: patch-src_hotspot_share_prims_jvmtiEnter.xsl,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/prims/jvmtiEnter.xsl.orig	2025-08-01 08:09:37.206406219 +0000
+++ src/hotspot/share/prims/jvmtiEnter.xsl
@@ -432,7 +432,7 @@ struct jvmtiInterface_1_ jvmti</xsl:text
   <xsl:if test="count(@impl)=0 or not(contains(@impl,'innative'))">
     <xsl:text>JavaThread* current_thread = (JavaThread*)this_thread;</xsl:text>   
     <xsl:value-of select="$space"/>
-    <xsl:text>MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, current_thread));</xsl:text>
+    <xsl:text>AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, current_thread));</xsl:text>
     <xsl:value-of select="$space"/>
     <xsl:text>ThreadInVMfromNative __tiv(current_thread);</xsl:text>
     <xsl:value-of select="$space"/>
