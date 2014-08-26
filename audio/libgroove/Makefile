# $NetBSD: Makefile,v 1.4 2014/08/26 20:54:40 joerg Exp $

DISTNAME=	3.1.1
PKGNAME=	libgroove-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/andrewrk/libgroove/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andrewrk/libgroove/
COMMENT=	Audio dispatching library
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	gmake pkg-config perl:build
USE_LANGUAGES=	c c++

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.endif

DIST_SUBDIR=	libgroove

.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
