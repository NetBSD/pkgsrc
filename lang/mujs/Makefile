# $NetBSD: Makefile,v 1.3 2023/01/23 15:42:08 wiz Exp $

DISTNAME=	mujs-1.3.2
CATEGORIES=	lang
MASTER_SITES=	https://mujs.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mujs.com/
COMMENT=	Lightweight embedded JavaScript interpreter
LICENSE=	isc

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	VERSION=${PKGVERSION_NOREV}
MAKE_FLAGS+=	HAVE_READLINE=yes

BUILD_TARGET=	shell shared build/release/mujs.pc
INSTALL_TARGET=	install-common install-shared

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		build/release/mujs.pc

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
