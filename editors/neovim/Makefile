# $NetBSD: Makefile,v 1.10 2024/08/17 15:42:32 bsiegert Exp $

DISTNAME=	neovim-0.10.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://neovim.org/
COMMENT=	Vim fork focused on extensibility and usability
LICENSE=	apache-2.0 AND vim-license

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config gettext

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	notdarwin
.if ${SHLIB_TYPE} == "dylib"
SHLIB_EXT=	dylib
.else
SHLIB_EXT=	so
PLIST.notdarwin=	yes
.endif

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DUSE_BUNDLED=OFF
CMAKE_CONFIGURE_ARGS+=	-DLIBVTERM_LIBRARY=${BUILDLINK_PREFIX.libvterm03}/lib/libvterm03/libvterm.${SHLIB_EXT}
CMAKE_CONFIGURE_ARGS+=	-DLIBVTERM_INCLUDE_DIR=${BUILDLINK_PREFIX.libvterm03}/include/libvterm03

LDFLAGS.SunOS+=		-lrt

# should follow the LuaJIT API compatibility
LUA_VERSIONS_ACCEPTED=	51

# https://github.com/neovim/neovim/issues/223#issuecomment-374763255
FORTIFY_SUPPORTED=	no

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-BitOp-[0-9]*:../../devel/lua-BitOp
DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-inspect-[0-9]*:../../devel/lua-inspect
DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg
DEPENDS+=	${LUA_PKGPREFIX}-mpack-[0-9]*:../../devel/lua-mpack

TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

post-install:
	${PREFIX}/bin/patchelf ${DESTDIR}${PREFIX}/bin/nvim \
		--replace-needed ${PREFIX}/lib/lua/5.1/lpeg.so lpeg.so
	${PREFIX}/bin/patchelf ${DESTDIR}${PREFIX}/bin/nvim \
		--add-rpath ${PREFIX}/lib/lua/5.1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.if ${OPSYS} == "SunOS"
.  include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/libuv/buildlink3.mk"
BUILDLINK_API_DEPENDS.libvterm03+=	libvterm03>=0.3.3
.include "../../devel/libvterm03/buildlink3.mk"
.include "../../devel/lua-luv/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
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
