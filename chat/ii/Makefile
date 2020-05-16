# $NetBSD: Makefile,v 1.4 2020/05/16 18:14:20 nia Exp $

DISTNAME=	ii-1.8
CATEGORIES=	chat
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://dl.suckless.org/tools/
COMMENT=	Minimalist FIFO and filesystem-based IRC client
LICENSE=	mit

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
