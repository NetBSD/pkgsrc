# $NetBSD: Makefile,v 1.7 2023/11/07 22:32:52 schmonz Exp $

PKGNAME=		${LUA_PKGPREFIX}-${PKGNAME_MODULE}
COMMENT=		Lua bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/lua/

CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		LUA_CFLAGS=-I${PREFIX:Q}/${LUA_INCDIR:Q}
CONFIGURE_ENV+=		LUA_LIBS=-L${PREFIX:Q}/${LUA_CDIR:Q}
MAKE_ENV+=		LUA_PKGPREFIX=${LUA_PKGPREFIX:Q}

REPLACE_LUA=		lua/docs/examples/*.lua

PLIST_SUBST+=		LUA_PKGPREFIX=${LUA_PKGPREFIX}

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/${LUA_PKGPREFIX}/examples/*.lua

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../lang/lua/tool.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
