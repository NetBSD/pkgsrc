# $NetBSD: Makefile,v 1.3 2020/07/02 10:26:18 nia Exp $

DISTNAME=		std._debug-1.0.1
PKGNAME=		${DISTNAME:S/std._debug/${LUA_PKGPREFIX}-std-_debug/}
CATEGORIES=		devel lua
MASTER_SITES=		${MASTER_SITE_GITHUB:=lua-stdlib/}
GITHUB_PROJECT=		_debug
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://lua-stdlib.github.io/_debug
COMMENT=		Debug Hints Library
LICENSE=		mit

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	${LUA_LDIR}/std/_debug ${LUA_DOCDIR}

.include "../../lang/lua/module.mk"

do-install:
.for i in init version
	${INSTALL_DATA} ${WRKSRC}/lib/std/_debug/${i}.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/std/_debug
.endfor
.for i in index.html ldoc.css
	${INSTALL_DATA} ${WRKSRC}/doc/${i} \
	                ${DESTDIR}${PREFIX}/${LUA_DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
