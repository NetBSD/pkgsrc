# $NetBSD: options.mk,v 1.1.1.1 2005/01/02 13:39:55 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bugzilla
PKG_SUPPORTED_OPTIONS=	ldap charts patchviewer xmlimportbugs

.include "../../mk/bsd.options.mk"

###
### Use OpenLDAP for authentication
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap
.endif

###
### Generation of charts
###
.if !empty(PKG_OPTIONS:Mcharts)
DEPENDS+=	gd>=1.20:../../graphics/gd
DEPENDS+=	p5-Chart>=1.0:../../graphics/p5-Chart
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
.endif

###
### Patchviewer support
###
.if !empty(PKG_OPTIONS:Mpatchviewer)
DEPENDS+=	p5-PatchReader>=0.9.4:../../devel/p5-PatchReader
DEPENDS+=	patchutils-[0-9]*:../../devel/patchutils
.endif

###
### Add support for bulk import/export of bugs in XML format
###
.if !empty(PKG_OPTIONS:Mxmlimportbugs)
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
.endif
