# $NetBSD: Makefile,v 1.2 2014/05/14 15:24:00 wiz Exp $

DISTNAME=	3.1.1
PKGNAME=	libgroove-${DISTNAME}
PKGREVISION=	1
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

.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
