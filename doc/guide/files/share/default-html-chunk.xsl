<?xml version='1.0' encoding="iso-8859-1"?>

<!-- $NetBSD: default-html-chunk.xsl,v 1.3 2006/05/24 07:54:11 mishka Exp $ -->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">

  <xsl:import href="http://www.NetBSD.org/XML/htdocs/share/xsl/netbsd-docbook-html-chunk.xsl" />

  <xsl:param name="chunker.output.indent" select="'yes'"/>
</xsl:stylesheet>
