# $NetBSD: Makefile,v 1.6 2023/09/10 09:57:36 nia Exp $

DISTNAME=	mujs-1.3.3
PKGREVISION=	2
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

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
