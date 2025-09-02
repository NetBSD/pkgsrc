# $NetBSD: Makefile,v 1.6 2025/09/02 20:24:02 vins Exp $

DISTNAME=	ii-2.0
CATEGORIES=	chat
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://tools.suckless.org/ii/
COMMENT=	Minimalist FIFO and filesystem-based IRC client
LICENSE=	mit

.include "options.mk"

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		MANPREFIX=${PREFIX}/${PKGMANDIR} \
		DOCPREFIX=${PREFIX}/share/doc

.include "../../mk/bsd.prefs.mk"

CFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.SunOS+=	-lsocket -lnsl

.if !${OPSYS:M*BSD} && ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
# build strlcpy() compatibility
CPPFLAGS+=	-DNEED_STRLCPY
MAKE_FLAGS+=	LIBS+=strlcpy.o
.endif

.include "../../mk/bsd.pkg.mk"
