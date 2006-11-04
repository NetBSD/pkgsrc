# $NetBSD: options.mk,v 1.1.1.1.14.1 2006/11/04 22:23:14 salo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bugzilla

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_OPTIONS_LEGACY_OPTS+=	patchviewer:bugzilla-patchviewer
PKG_OPTIONS_LEGACY_OPTS+=	xmlimportbugs:bugzilla-xmlimportbugs
PKG_OPTIONS_LEGACY_OPTS+=	charts:bugzilla-charts

PKG_SUPPORTED_OPTIONS=	ldap bugzilla-charts bugzilla-patchviewer mysql pgsql
PKG_SUPPORTED_OPTIONS+=	bugzilla-xmlimportbugs bugzilla-imagemagick
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql or postgresql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=2.9003:../../databases/p5-DBD-mysql
DBDRIVER=	mysql
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=1.45:../../databases/p5-DBD-postgresql
DBDRIVER=	pgsql
.endif

###
### If you want to convert BMP image attachments to PNG to conserve
### disk space.
###
.if !empty(PKG_OPTIONS:Mbugzilla-imagemagick)
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick
.endif

###
### Use OpenLDAP for authentication
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap
.endif

###
### Generation of charts
###
.if !empty(PKG_OPTIONS:Mbugzilla-charts)
DEPENDS+=	gd>=1.20:../../graphics/gd
DEPENDS+=	p5-Chart>=1.0:../../graphics/p5-Chart
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
.endif

###
### Patchviewer support
###
.if !empty(PKG_OPTIONS:Mbugzilla-patchviewer)
DEPENDS+=	p5-PatchReader>=0.9.4:../../devel/p5-PatchReader
DEPENDS+=	patchutils-[0-9]*:../../devel/patchutils
.endif

###
### Add support for bulk import/export of bugs in XML format
###
.if !empty(PKG_OPTIONS:Mbugzilla-xmlimportbugs)
DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig
.endif
