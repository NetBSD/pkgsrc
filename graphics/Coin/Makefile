# $NetBSD: Makefile,v 1.27 2014/05/15 14:41:51 adam Exp $

DISTNAME=		Coin-3.1.3
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		https://bitbucket.org/Coin3D/coin/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Free, portable, Open Inventor API implementation
LICENSE=		modified-bsd
# See https://bitbucket.org/Coin3D/coin/wiki/EndOfLifeLetter

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-3ds-import
CONFIGURE_ARGS+=	--disable-debug

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
CONFIGURE_ARGS+=	--with-pthreads=yes
CONFIGURE_ARGS+=	--enable-threadsafe
.endif

.include "../../graphics/simage/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
