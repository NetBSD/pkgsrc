# $NetBSD: Makefile,v 1.7 2015/12/13 18:19:05 alnsn Exp $
#

DISTNAME=	LuaJIT-2.0.4
PKGNAME=	${DISTNAME:S/LuaJIT/LuaJIT2/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

USE_TOOLS+=	gmake

# Address pkg/47587 lua not linked to pthread causes issues with modules
PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
