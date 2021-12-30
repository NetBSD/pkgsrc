# $NetBSD: Makefile,v 1.1 2021/12/30 00:26:20 nia Exp $

DISTNAME=	3dpong-0.5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/3dpong/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/3dpong/index2.php3
COMMENT=	One or two player 3D sports game based on Pong from Atari
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	XLIB="${LDFLAGS} -lX11"
MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
