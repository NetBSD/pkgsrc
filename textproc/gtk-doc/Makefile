# $NetBSD: Makefile,v 1.31 2008/04/25 05:26:29 wiz Exp $
#

DISTNAME=	gtk-doc-1.10
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/1.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtk.org/gtk-doc/
COMMENT=	Tools for authors of the GTK+ reference documentation

DEPENDS+=	docbook-xml>=4.4nb1:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG:Q}
USE_DIRS+=		gnome2-1.6
USE_TOOLS+=		perl:run

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtkdoc
PKG_SUPPORTED_OPTIONS=	sgml
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msgml)
DEPENDS+= dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
SGML_CATALOGS= ${PREFIX}/share/sgml/gtk-doc/gtk-doc.cat
.include "../../textproc/jade/buildlink3.mk"
.endif

.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
