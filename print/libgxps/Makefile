# $NetBSD: Makefile,v 1.4.2.1 2012/10/03 12:09:16 spz Exp $
#

DISTNAME=	libgxps-0.2.2
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgxps/0.2/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Library for XPS documents
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libgxps.pc.in

pre-configure:
	${CP} ${FILESDIR}/libarchive.pc ${BUILDLINK_DIR}/lib/pkgconfig

# for test
#.include "../../x11/gtk3/buildlink3.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
