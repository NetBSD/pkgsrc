# $NetBSD: options.mk,v 1.3 2013/01/19 20:27:30 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sqsh
PKG_SUPPORTED_OPTIONS+=		sybase-openclient
PKG_OPTIONS_OPTIONAL_GROUPS+=	x11
PKG_OPTIONS_GROUP.x11+=		sqsh-motif sqsh-xaw
PKG_OPTIONS_LEGACY_VARS+=	USE_SYBASE_OPENCLIENT:sybase-openclient

.include "../../mk/bsd.options.mk"

###
### Motif GUI support.
###
.if !empty(PKG_OPTIONS:Msqsh-motif)
.  include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-motif=${MOTIFBASE:Q}
.endif

###
### Athena GUI support.
###
.if !empty(PKG_OPTIONS:Msqsh-xaw)
.  include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x
.endif

###
### Common dependencies for X GUI support.
###
.if !empty(PKG_OPTIONS:Msqsh-motif) || !empty(PKG_OPTIONS:Msqsh-xaw)
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXmu/buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.endif

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
