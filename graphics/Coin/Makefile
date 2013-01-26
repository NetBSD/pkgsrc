# $NetBSD: Makefile,v 1.21 2013/01/26 21:36:26 adam Exp $

DISTNAME=		Coin-2.4.4
PKGREVISION=		10
CATEGORIES=		graphics
MASTER_SITES=		http://ftp.coin3d.org/coin/src/all/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Free, portable, Open Inventor API implementation

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
