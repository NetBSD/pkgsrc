# $NetBSD: options.mk,v 1.4 2013/12/09 14:17:42 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bugzilla

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql oracle

PKG_SUPPORTED_OPTIONS=	bugzilla-notify bugzilla-graphicalreports
PKG_SUPPORTED_OPTIONS+=	bugzilla-inboundemail bugzilla-movebugs
PKG_SUPPORTED_OPTIONS+=	bugzilla-imagemagick bugzilla-patchviewer
PKG_SUPPORTED_OPTIONS+=	bugzilla-descriptions bugzilla-xmlrpc
PKG_SUPPORTED_OPTIONS+=	bugzilla-modperl radius
PKG_SUPPORTED_OPTIONS+=	mysql pgsql oracle ldap
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use mysql or postgresql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=4.000:../../databases/p5-DBD-mysql
DBDRIVER=	mysql
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=1.45:../../databases/p5-DBD-postgresql
DBDRIVER=	pg
.elif !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	p5-DBD-Oracle>=1.19:../../databases/p5-DBD-Oracle
DBDRIVER=	oracle
.endif

###
### Automatic Update Notifications
###
.if !empty(PKG_OPTIONS:Mbugzilla-notify)
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
.endif

###
### RADIUS authentication
###
.if !empty(PKG_OPTIONS:Mradius)
DEPENDS+=	p5-RadiusPerl-[0-9]*:../../net/p5-RadiusPerl
.endif

###
### More HTML in Product/Group Descriptions
###
.if !empty(PKG_OPTIONS:Mbugzilla-descriptions)
DEPENDS+=	p5-HTML-Scrubber-[0-9]*:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-HTML-Parser>=3.40:../../www/p5-HTML-Parser
.endif

###
### mod_perl
###
.if !empty(PKG_OPTIONS:Mbugzilla-modperl)
DEPENDS+=	{perl>=5.9.3,p5-CGI>=3.11}:../../www/p5-CGI
DEPENDS+=	p5-Apache-DBI>=0.96:../../databases/p5-Apache-DBI
. if defined(PKG_APACHE)
.  if !empty(PKG_APACHE:Mapache2)
.   include "../../www/ap2-perl/buildlink3.mk"
.  elif !empty(PKG_APACHE:Mapache22)
.   include "../../www/ap2-perl/buildlink3.mk"
.  elif !empty(PKG_APACHE:Mapache13)
.   include "../../www/ap-perl/buildlink3.mk"
.  endif
. endif
.endif

###
### XML-RPC Interface
###
.if !empty(PKG_OPTIONS:Mbugzilla-xmlrpc)
DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
.endif

###
### Inbound Email
###
.if !empty(PKG_OPTIONS:Mbugzilla-inboundemail)
DEPENDS+=	p5-Email-MIME-Attachment-Stripper-[0-9]*:../../mail/p5-Email-MIME-Attachment-Stripper
DEPENDS+=	p5-Email-Reply-[0-9]*:../../mail/p5-Email-Reply
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
### Generation of graphical reports
###
.if !empty(PKG_OPTIONS:Mbugzilla-graphicalreports)
DEPENDS+=	gd>=1.20:../../graphics/gd
DEPENDS+=	p5-Chart>=1.0:../../graphics/p5-Chart
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
DEPENDS+=	p5-Template-GD-[0-9]*:../../graphics/p5-Template-GD
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
.if !empty(PKG_OPTIONS:Mbugzilla-movebugs)
DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig
DEPENDS+=	p5-MIME-tools>=5.406:../../mail/p5-MIME-tools
.endif
