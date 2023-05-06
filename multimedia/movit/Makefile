# $NetBSD: Makefile,v 1.9 2023/05/06 19:09:44 ryoon Exp $

DISTNAME=	movit-1.6.3
PKGREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	https://movit.sesse.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://movit.sesse.net/
COMMENT=	High-performance, high-quality video filters for the GPU
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

BUILD_TARGET=	libmovit.la

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
