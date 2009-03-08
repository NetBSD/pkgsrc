# $NetBSD: Makefile,v 1.36 2009/03/08 15:56:47 wiz Exp $
#

DISTNAME=	gtk-doc-1.11
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/1.11/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtk.org/gtk-doc/
COMMENT=	Tools for authors of the GTK+ reference documentation

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	docbook-xml>=4.4nb1:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG:Q}
USE_DIRS+=		gnome2-1.6
USE_TOOLS+=		gmake perl:run pkg-config

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
