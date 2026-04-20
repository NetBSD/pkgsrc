# $NetBSD: Makefile,v 1.12 2026/04/20 16:13:30 vins Exp $

DISTNAME=	ximaging-src-1.9.1
PKGNAME=	${DISTNAME:S,-src,,}
CATEGORIES=	graphics
MASTER_SITES=	https://fastestcode.org/dl/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://fastestcode.org/emwm.html
COMMENT=	Image browser and viewer for Unix - X/Motif
LICENSE=	mit

PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	mf/Makefile.pkgsrc
SUBST_VARS.pkgsrc+=	PREFIX PKGMANDIR RCDIR
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

# Enable OpenMP loop optimizations
MAKE_FLAGS+=	ENABLE_OMP=1

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
