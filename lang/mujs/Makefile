# $NetBSD: Makefile,v 1.5 2023/09/10 09:36:38 nia Exp $

DISTNAME=	mujs-1.3.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://mujs.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mujs.com/
COMMENT=	Lightweight embedded JavaScript interpreter
LICENSE=	isc

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

MAKE_FLAGS+=	prefix=${PREFIX}
BUILD_TARGET=	default
INSTALL_TARGET=	install-shared

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
