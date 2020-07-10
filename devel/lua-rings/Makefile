# $NetBSD: Makefile,v 1.1 2020/07/10 11:18:01 nia Exp $

DISTNAME=	rings-1.3.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_PROJECT=	rings
GITHUB_TAG=	v_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keplerproject.github.io/rings/
COMMENT=	Library which provides a way to create new Lua states from within Lua
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	gmake

MAKE_FLAGS+=	LUA_LIBDIR=${PREFIX}/${LUA_CDIR}
MAKE_FLAGS+=	LUA_DIR=${PREFIX}/${LUA_LDIR}
MAKE_FLAGS+=	LUA_INC=${LUA_INCDIR}

INSTALLATION_DIRS+=	${LUA_DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/us/* ${DESTDIR}${PREFIX}/${LUA_DOCDIR}

do-test:
	cd ${WRKSRC}/tests && \
		LUA_CPATH=${WRKSRC}/src/?.so \
		LUA_PATH=${WRKSRC}/src/?.lua \
		${LUA_INTERPRETER} sample_state.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
