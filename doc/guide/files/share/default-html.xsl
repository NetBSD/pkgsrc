<?xml version='1.0'?>

<!-- $NetBSD: default-html.xsl,v 1.4 2025/10/09 16:57:32 martin Exp $ -->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">

  <xsl:import href="http://www.NetBSD.org/XML/htdocs/share/xsl/netbsd-docbook-html.xsl" />

  <xsl:output method="html" indent="yes" encoding="utf-8"
	doctype-public="-//W3C//DTD HTML 4.01 Transitional//EN"/>
</xsl:stylesheet>
