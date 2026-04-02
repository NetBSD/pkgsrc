# $NetBSD: Makefile,v 1.23 2026/04/02 17:25:44 leot Exp $

DISTNAME=	neovim-0.11.7
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://neovim.io/
COMMENT=	Vim fork focused on extensibility and usability
LICENSE=	apache-2.0 AND vim-license

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gettext

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	desktop
.if ${OPSYS} != "Darwin"
PLIST.desktop=	yes
.endif

PRINT_PLIST_AWK+=	{ gsub(/^share\/applications\/nvim\.desktop$$/, "$${PLIST.desktop}&"); }

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TRANSLATIONS=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_BUNDLED=OFF

LDFLAGS.SunOS+=		-lrt

# should follow the LuaJIT API compatibility
LUA_VERSIONS_ACCEPTED=	51

# https://github.com/neovim/neovim/issues/223#issuecomment-374763255
FORTIFY_SUPPORTED=	no

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-BitOp-[0-9]*:../../devel/lua-BitOp
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-inspect-[0-9]*:../../devel/lua-inspect
DEPENDS+=	${LUA_PKGPREFIX}-mpack-[0-9]*:../../devel/lua-mpack

.if ${SHLIB_TYPE} == "ELF"
CFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/lua/5.1

TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

post-install:
	${TOOLBASE}/bin/patchelf ${DESTDIR}${PREFIX}/bin/nvim \
		--replace-needed ${BUILDLINK_DIR.lua-lpeg}/lib/lua/5.1/lpeg.so lpeg.so
.endif

# due to pkgsrc patches, remove when they are gone
.PHONY: cleanorig
post-install: cleanorig
cleanorig:
	${RM} ${DESTDIR}${PREFIX}/share/nvim/runtime/lua/vim/treesitter/_meta/misc.lua.orig
	${RM} ${DESTDIR}${PREFIX}/share/nvim/runtime/lua/vim/treesitter/languagetree.lua.orig

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.if ${OPSYS} == "SunOS"
.  include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/lua-lpeg/buildlink3.mk"
.include "../../devel/lua-luv/buildlink3.mk"
.include "../../devel/unibilium/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../lang/LuaJIT2/platform.mk"
.if ${PLATFORM_SUPPORTS_LUAJIT:tl} == "yes"
BUILDLINK_API_DEPENDS.LuaJIT2+=	LuaJIT2>=2.1
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DPREFER_LUA=ON
.  include "../../lang/lua/buildlink3.mk"
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/tree-sitter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
