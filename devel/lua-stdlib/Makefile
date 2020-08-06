# $NetBSD: Makefile,v 1.9 2020/08/06 23:45:07 joerg Exp $

DISTNAME=		stdlib-41.2.2
PKGNAME=		${DISTNAME:S/stdlib/${LUA_PKGPREFIX}-stdlib/}
CATEGORIES=		devel lua
MASTER_SITES=		${MASTER_SITE_GITHUB:=lua-stdlib/}
GITHUB_PROJECT=		lua-stdlib
GITHUB_TAG=		release-v${PKGVERSION_NOREV}

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		https://github.com/lua-stdlib/lua-stdlib/tags
COMMENT=		Standard library for Lua programming language
LICENSE=		mit

NO_BUILD=		yes
NO_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/lua-stdlib-${GITHUB_TAG}

INSTALLATION_DIRS+=	${LUA_LDIR}/std/debug_init \
			${LUA_DOCDIR}/std/classes \
			${LUA_DOCDIR}/std/modules

.include "../../lang/lua/module.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/std/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/std/
	${INSTALL_DATA} ${WRKSRC}/lib/std/debug_init/*.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/std/debug_init/
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${WRKSRC}/doc/ldoc.css \
			${DESTDIR}${PREFIX}/${LUA_DOCDIR}/std
	${INSTALL_DATA} ${WRKSRC}/doc/classes/*.html \
			${DESTDIR}${PREFIX}/${LUA_DOCDIR}/std/classes
	${INSTALL_DATA} ${WRKSRC}/doc/modules/*.html \
			${DESTDIR}${PREFIX}/${LUA_DOCDIR}/std/modules

.include "../../mk/bsd.pkg.mk"
