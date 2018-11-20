# $NetBSD: Makefile,v 1.1 2018/11/20 17:29:24 maya Exp $

DISTNAME=		std.normalize-2.0.2
PKGNAME=		${DISTNAME:S/std.normalize/${LUA_PKGPREFIX}-std-normalize/}
GITHUB_PROJECT=		normalize
GITHUB_TAG=		v${PKGVERSION_NOREV}
MASTER_SITES=		${MASTER_SITE_GITHUB:=lua-stdlib/}

CATEGORIES=		devel
COMMENT=		Normalized Lua functions
MAINTAINER=		pkgsrc-users@NetBSD.org

HOMEPAGE=		https://lua-stdlib.github.io/normalize
LICENSE=		mit

DEPENDS+=		${LUA_PKGPREFIX}-std-_debug-[0-9]*:../../devel/lua-std-_debug

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	${LUA_LDIR}/std/normalize ${LUA_DOCDIR}

.include "../../lang/lua/module.mk"

do-install:
.for i in _base _strict _typecheck init version
	${INSTALL_DATA} ${WRKSRC}/lib/std/normalize/${i}.lua \
	                ${DESTDIR}${PREFIX}/${LUA_LDIR}/std/normalize
.endfor
.for i in index.html ldoc.css
	${INSTALL_DATA} ${WRKSRC}/doc/${i} \
	                ${DESTDIR}${PREFIX}/${LUA_DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
