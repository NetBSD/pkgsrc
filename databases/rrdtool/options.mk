# $NetBSD: options.mk,v 1.7 2019/02/11 08:22:44 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rrdtool
PKG_SUPPORTED_OPTIONS=	lua tcl
PKG_SUGGESTED_OPTIONS=	lua tcl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		lua tcl

.if !empty(PKG_OPTIONS:Mtcl)
USE_TOOLS+=		tclsh:run
CONFIGURE_ARGS+=	--enable-tcl
CONFIGURE_ARGS+=	--with-tcllib=${BUILDLINK_PREFIX.tcl}/lib

REPLACE_INTERPRETER+=	tclsh
REPLACE.tclsh.old=	.*tclsh@TCL_VERSION@
REPLACE.tclsh.new=	${BUILDLINK_PREFIX.tcl}/bin/tclsh
REPLACE_FILES.tclsh=	bindings/tcl/ifOctets.tcl.in

PLIST.tcl=		yes

.  if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	install_name_tool -id ${PREFIX}/lib/tclrrd${PKGVERSION_NOREV}.dylib \
		${DESTDIR}${PREFIX}/lib/tclrrd${PKGVERSION_NOREV}.dylib
.  endif

.include "../../lang/tcl/buildlink3.mk"

.else # tcl
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--enable-lua
CONFIGURE_ENV+=		ac_cv_path_LUA=${LUA_INTERPRETER}
PLIST.lua=		yes
.include "../../lang/lua/module.mk"
.else
CONFIGURE_ARGS+=	--disable-lua
.endif
