# $NetBSD: Makefile,v 1.2 2020/07/02 10:26:18 nia Exp $

DISTNAME=		std.normalize-2.0.2
PKGNAME=		${DISTNAME:S/std.normalize/${LUA_PKGPREFIX}-std-normalize/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=lua-stdlib/}
GITHUB_PROJECT=		normalize
GITHUB_TAG=		v${PKGVERSION_NOREV}

HOMEPAGE=		https://lua-stdlib.github.io/normalize
COMMENT=		Normalized Lua functions
LICENSE=		mit
MAINTAINER=		pkgsrc-users@NetBSD.org

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
