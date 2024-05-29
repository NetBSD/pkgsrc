# $NetBSD: Makefile,v 1.22 2024/05/29 16:34:12 adam Exp $

DISTNAME=	sile-0.14.8
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=sile-typesetter/}
GITHUB_PROJECT=	sile
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sile-typesetter.org/
COMMENT=	Modern Layout Engine with Lua based scripting
LICENSE=	mit

DEPENDS+=	${LUA_PKGPREFIX}-zlib-[0-9]*:../../archivers/lua-zlib
DEPENDS+=	${LUA_PKGPREFIX}-bit32-[0-9]*:../../devel/lua-bit32
DEPENDS+=	${LUA_PKGPREFIX}-cliargs-[0-9]*:../../devel/lua-cliargs
DEPENDS+=	${LUA_PKGPREFIX}-compat53-[0-9]*:../../devel/lua-compat53
DEPENDS+=	${LUA_PKGPREFIX}-loadkit-[0-9]*:../../devel/lua-loadkit
DEPENDS+=	${LUA_PKGPREFIX}-epnf-[0-9]*:../../devel/lua-epnf
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-linenoise-[0-9]*:../../devel/lua-linenoise
DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-penlight-[0-9]*:../../devel/lua-penlight
DEPENDS+=	${LUA_PKGPREFIX}-repl-[0-9]*:../../devel/lua-repl
DEPENDS+=	${LUA_PKGPREFIX}-rocks-[0-9]*:../../devel/lua-rocks
DEPENDS+=	${LUA_PKGPREFIX}-stdlib-[0-9]*:../../devel/lua-stdlib
DEPENDS+=	${LUA_PKGPREFIX}-vstruct-[0-9]*:../../devel/lua-vstruct
DEPENDS+=	${LUA_PKGPREFIX}-cassowary-[0-9]*:../../math/lua-cassowary
DEPENDS+=	${LUA_PKGPREFIX}-socket-[0-9]*:../../net/lua-socket
DEPENDS+=	${LUA_PKGPREFIX}-sec-[0-9]*:../../security/lua-sec
DEPENDS+=	${LUA_PKGPREFIX}-expat-[0-9]*:../../textproc/lua-expat
DEPENDS+=	${LUA_PKGPREFIX}-fluent-[0-9]*:../../textproc/lua-fluent
DEPENDS+=	${LUA_PKGPREFIX}-cosmo-[0-9]*:../../textproc/lua-cosmo
DEPENDS+=	${LUA_PKGPREFIX}-utf8-[0-9]*:../../textproc/lua-utf8

DEPENDS+=	gentiumplus-ttf-[0-9]*:../../fonts/gentiumplus-ttf

.if 0
# Tests require additional font downloads and extra tools before configure
pre-configure:
	${LN} -fs ${PREFIX}/bin/busted${_LUA_DOT_VERSION} ${TOOLS_DIR}/bin/busted
	${LN} -fs ${PREFIX}/bin/luacheck-${_LUA_DOT_VERSION} ${TOOLS_DIR}/bin/luacheck
	${LN} -fs ${PREFIX}/bin/luarocks-${_LUA_DOT_VERSION} ${TOOLS_DIR}/bin/luarocks

TEST_DEPENDS+=	${LUA_PKGPREFIX}-busted-[0-9]*:../../devel/lua-busted
TEST_DEPENDS+=	${LUA_PKGPREFIX}-check-[0-9]*:../../devel/lua-check

USE_TOOLS+=	perl:test
TEST_TARGET=	test
CONFIGURE_ARGS+= 	--enable-developer
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash pkg-config gmake

CONFIG_SHELL=		${BASH}
CONFIGURE_ARGS+=	LUA=${LUA_INTERPRETER} GIT=${FALSE}
CONFIGURE_ARGS+=	--with-system-luarocks

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
