# $NetBSD: Makefile,v 1.1.1.1 2019/01/26 00:57:56 alnsn Exp $

DISTNAME=	cqueues-20171014
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://25thandclement.com/~william/projects/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://25thandclement.com/~william/projects/releases/
COMMENT=	Stackable Continuation Queues for Lua
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

MAKE_ENV+=	prefix=${PREFIX}

BUILD_TARGET=	all${_LUA_DOT_VERSION}
INSTALL_TARGET=	install${_LUA_DOT_VERSION}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
