# $NetBSD: Makefile,v 1.4 2023/04/24 07:50:40 wiz Exp $

DISTNAME=	mujs-1.3.3
CATEGORIES=	lang
MASTER_SITES=	https://mujs.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mujs.com/
COMMENT=	Lightweight embedded JavaScript interpreter
LICENSE=	isc

USE_TOOLS+=	gmake

MAKE_FLAGS+=	prefix=${PREFIX}
BUILD_TARGET=	default

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
