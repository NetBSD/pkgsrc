# $NetBSD: Makefile,v 1.5 2022/08/22 17:47:51 tnn Exp $

DISTNAME=	ii-1.8
CATEGORIES=	chat
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://dl.suckless.org/tools/
COMMENT=	Minimalist FIFO and filesystem-based IRC client
LICENSE=	mit

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

CFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
