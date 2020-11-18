# $NetBSD: Makefile,v 1.1 2020/11/18 14:31:43 schmonz Exp $

DISTNAME=	ucspi-unix-1.0
CATEGORIES=	net sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://untroubled.org/ucspi-unix/
COMMENT=	UCSPI client and server for Unix domain sockets
LICENSE=	gnu-gpl-v2

DJB_RESTRICTED=		no
DJB_MAKE_TARGETS=	no
USE_TOOLS+=		gmake

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX:Q}
INSTALL_MAKE_FLAGS+=	mandir=${PKGMANDIR:Q}

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
