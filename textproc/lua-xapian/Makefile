# $NetBSD: Makefile,v 1.1 2017/07/10 17:34:04 schmonz Exp $

PKGNAME=		${LUA_PKGPREFIX}-${PKGNAME_MODULE}
COMMENT=		Lua bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/lua/

CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		LUA_INC=${BUILDLINK_INCDIRS.${LUA_PACKAGE}}

REPLACE_LUA=		lua/docs/examples/*.lua

post-install:
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/doc/xapian-bindings/lua/examples/*.lua

.include "../../lang/lua/application.mk"
.include "../../lang/lua/module.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
