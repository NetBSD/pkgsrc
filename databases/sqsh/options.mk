# $NetBSD: options.mk,v 1.4 2016/12/30 13:33:45 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sqsh
PKG_SUPPORTED_OPTIONS=		sybase-openclient

.include "../../mk/bsd.options.mk"

###
### Support for the native Sybase Open Client.
###
.if !empty(PKG_OPTIONS:Msybase-openclient)
BUILD_DEFS+=		SYBASE
.  if defined(SYBASE) && exists(${SYBASE}/lib/libct.so)
BUILDLINK_PASSTHRU_DIRS+=	${SYBASE}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${SYBASE:Q}/lib
LIBS.SunOS+=		-lsocket
CONFIGURE_ARGS+=	--with-static
CONFIGURE_ENV+=		SYBASE=${SYBASE:Q}
.  else
PKG_FAIL_REASON+=	"You must define SYBASE to the base directory of Open Client."
.  endif
.else
.  include "../../databases/freetds/buildlink3.mk"
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX:Q}/lib
CONFIGURE_ENV+=		SYBASE=${BUILDLINK_PREFIX.freetds:Q}
CONFIGURE_ENV+=		SYBASE_LIBS=-lct
MAKE_FLAGS+=		SYBASE_LIBS=-lct
.endif
