# $NetBSD: Makefile,v 1.7 2025/10/12 14:41:43 vins Exp $

DISTNAME=	ii-2.0
PKGREVISION=	1
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
CPPFLAGS+=	-DNEED_STRLCPY
MAKE_FLAGS+=	LIBS+=strlcpy.o
.endif

.include "../../mk/bsd.pkg.mk"
