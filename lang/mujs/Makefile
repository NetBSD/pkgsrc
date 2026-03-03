# $NetBSD: Makefile,v 1.8 2026/03/03 21:37:12 yhardy Exp $

DISTNAME=	mujs-1.3.9
CATEGORIES=	lang
MASTER_SITES=	https://mujs.com/downloads/

# understands the libtool patches
MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://mujs.com/
COMMENT=	Lightweight embedded JavaScript interpreter
LICENSE=	isc

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

MAKE_FLAGS+=	prefix=${PREFIX}
BUILD_TARGET=	default
INSTALL_TARGET=	install-shared

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		build/release/mujs.pc

INSTALLATION_DIRS+=		include/mujs

# needed by print/mupdf
post-install:
	${INSTALL_DATA} ${WRKSRC}/regexp.h ${DESTDIR}${PREFIX}/include/mujs/

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
