<?xml version='1.0' encoding="utf-8"?>

<!-- $NetBSD: default-html-chunk.xsl,v 1.4 2025/10/09 16:57:32 martin Exp $ -->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">

  <xsl:import href="http://www.NetBSD.org/XML/htdocs/share/xsl/netbsd-docbook-html-chunk.xsl" />

  <xsl:param name="chunker.output.indent" select="'yes'"/>
</xsl:stylesheet>
