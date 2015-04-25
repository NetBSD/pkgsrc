# $NetBSD: Makefile,v 1.3 2015/04/25 14:23:12 tnn Exp $

DISTNAME=	gmic_1.5.9.3
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gmic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/gmic/
COMMENT=	Full-featured image processing framework
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	src
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake gunzip pkg-config
CFLAGS+=	-I${BUILDLINK_PREFIX.openexr}/include/OpenEXR

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/fr/man1 && gunzip gmic.1.gz
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && gunzip gmic.1.gz

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
