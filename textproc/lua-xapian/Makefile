# $NetBSD: Makefile,v 1.5 2020/07/02 10:26:19 nia Exp $

PKGNAME=		${LUA_PKGPREFIX}-${PKGNAME_MODULE}

HOMEPAGE=		https://xapian.org/docs/bindings/lua/
COMMENT=		Lua bindings for Xapian search engine

CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		LUA_INC=${BUILDLINK_INCDIRS.${LUA_PACKAGE}}
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
