# $NetBSD: Makefile,v 1.13 2018/11/14 22:21:39 kleink Exp $

DISTNAME=	gmic_1.5.9.3
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gmic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gmic/
COMMENT=	Full-featured image processing framework
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	src
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake gunzip pkg-config
CFLAGS+=	-I${BUILDLINK_PREFIX.openexr}/include/OpenEXR
MAKE_ENV+=	BUILDLINK_PREFIX.fftw3=${BUILDLINK_PREFIX.fftw3}

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/fr/man1 && gunzip gmic.1.gz
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && gunzip gmic.1.gz

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
