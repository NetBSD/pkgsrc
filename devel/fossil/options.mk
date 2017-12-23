# $NetBSD: options.mk,v 1.1 2017/12/23 21:11:32 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fossil
PKG_SUPPORTED_OPTIONS=	fossil-system-sqlite fossil-th1-hooks json tcl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfossil-system-sqlite)
CONFIGURE_ARGS+=	--disable-internal-sqlite
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.20.0
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfossil-th1-hooks)
CONFIGURE_ARGS+=	--with-th1-hooks
.endif

.if !empty(PKG_OPTIONS:Mjson)
CONFIGURE_ARGS+=	--json
.endif

.if !empty(PKG_OPTIONS:Mtcl)
CONFIGURE_ARGS+=	--with-tcl
CONFIGURE_ARGS+=	--with-tcl-private-stubs
.include "../../lang/tcl/buildlink3.mk"
.endif
