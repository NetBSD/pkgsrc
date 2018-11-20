# $NetBSD: Makefile,v 1.1 2018/11/20 17:28:10 maya Exp $

DISTNAME=		std._debug-1.0
PKGNAME=		${DISTNAME:S/std._debug/${LUA_PKGPREFIX}-std-_debug/}
GITHUB_PROJECT=		_debug
GITHUB_TAG=		v${PKGVERSION_NOREV}
MASTER_SITES=		${MASTER_SITE_GITHUB:=lua-stdlib/}

CATEGORIES=		devel
COMMENT=		Debug Hints Library
MAINTAINER=		pkgsrc-users@NetBSD.org

HOMEPAGE=		https://lua-stdlib.github.io/_debug
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
