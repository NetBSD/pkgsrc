# $NetBSD: Makefile,v 1.17 2003/09/23 12:18:57 recht Exp $
#

DISTNAME=		libglade-2.0.1
PKGNAME=		${DISTNAME:S/libglade/libglade2/}
PKGREVISION=		10
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglade/2.0/}

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE GUI files (v2)

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	libglade-2.0.pc.in

CONFIGURE_ENV+=		jh_cv_path_python="${PYTHONBIN}"
CONFIGURE_ARGS+=	--enable-gtk-doc=no

XML_ENTRIES=	system http://glade.gnome.org/glade-2.0.dtd \
		${PREFIX}/share/xml/libglade/glade-2.0.dtd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/libglade/2.0

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
