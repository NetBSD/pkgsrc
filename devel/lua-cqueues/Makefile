# $NetBSD: Makefile,v 1.2 2019/08/29 20:16:49 alnsn Exp $

DISTNAME=	cqueues-20171014
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://25thandclement.com/~william/projects/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://25thandclement.com/~william/projects/releases/
COMMENT=	Stackable Continuation Queues for Lua
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake m4

MAKE_ENV+=	prefix=${PREFIX}

BUILD_TARGET=	all${_LUA_DOT_VERSION}
INSTALL_TARGET=	install${_LUA_DOT_VERSION}

.include "../../lang/lua/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
