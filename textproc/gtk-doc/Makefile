# $NetBSD: Makefile,v 1.55 2015/01/10 15:21:41 prlw1 Exp $

DISTNAME=	gtk-doc-1.21
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtk.org/gtk-doc/
COMMENT=	Tools for authors of the GTK+ reference documentation
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.1

BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
DEPENDS+=	docbook-xml>=4.4nb1:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG:Q}
USE_TOOLS+=		gmake perl:run pkg-config:run msgfmt

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.21

.include "../../lang/python/application.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
# needed together with pkg-config by gtkdoc-depscan at runtime
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
