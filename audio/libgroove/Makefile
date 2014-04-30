# $NetBSD: Makefile,v 1.1 2014/04/30 23:42:52 wiz Exp $

DISTNAME=	3.1.1
PKGNAME=	libgroove-${DISTNAME}
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

DIST_SUBDIR=	libgroove

# libav has to be built first but isn't
# https://github.com/andrewrk/libgroove/issues/59
MAKE_JOBS_SAFE=	no

# for included libav
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.include "../../audio/lame/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"

.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
