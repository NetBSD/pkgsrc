# $NetBSD: options.mk,v 1.13 2017/09/10 20:03:49 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.clisp

PKG_SUPPORTED_OPTIONS+=		doc
# this option is essential for some others to work:
PKG_SUPPORTED_OPTIONS+=		ffcall
PKG_SUPPORTED_OPTIONS+=		gmalloc
PKG_SUPPORTED_OPTIONS+=		readline
PKG_SUGGESTED_OPTIONS+=		ffcall readline doc

# CLISP doesn't work with jemalloc:
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=		gmalloc
.elif ${OPSYS} == "FreeBSD" && !empty(OS_VERSION:N[0-6].*)
PKG_SUGGESTED_OPTIONS+=		gmalloc
.endif

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.for option in ${PKG_SUPPORTED_OPTIONS}
.  if !empty(PKG_OPTIONS:M${option})
PLIST.${option}=	yes
.  endif
.endfor

.if !empty(PKG_OPTIONS:Mgmalloc)
CONFIGURE_ARGS+=	--with-gmalloc
.endif

.if !empty(PKG_OPTIONS:Mffcall)
CONFIGURE_ARGS+=	--with-dynamic-ffi
.  include "../../devel/libffcall/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mreadline)
CONFIGURE_ARGS+=	--with-readline
BUILDLINK_API_DEPENDS.readline+=	readline>=7.0
.include "../../devel/readline/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdoc)
USE_TOOLS+=		dvipdf groff
.else
# suppress generation of printable documentation
CONFIGURE_ENV+=		PS2PDF= ac_cv_prog_PS2PDF=
.endif


# Options for those who wishes to build "static" CLISP:

#.if !empty(PKG_OPTIONS:Mwildcard)
#CONFIGURE_ARGS+=	--with-module=wildcard
#.endif

#.if !empty(PKG_OPTIONS:Mpari)
#CONFIGURE_ARGS+=	--with-module=pari
#.  include "../../math/pari/buildlink3.mk"
#.endif

#.if !empty(PKG_OPTIONS:Mmit-clx)
#CONFIGURE_ARGS+=	--with-module=clx/mit-clx
#.  include "../../x11/libX11/buildlink3.mk"
#.  include "../../x11/libXau/buildlink3.mk"
#.endif

#.if !empty(PKG_OPTIONS:Mnew-clx)
#CONFIGURE_ARGS+=	--with-module=clx/new-clx
#.  include "../../x11/libX11/buildlink3.mk"
#.  include "../../x11/libXau/buildlink3.mk"
#.endif

#.if !empty(PKG_OPTIONS:Mbdb)
# it requires version 4, not anything older
#CONFIGURE_ARGS+=	--with-module=berkeley-db
#BUILDLINK_TRANSFORM+=	l:db:db46
#.  include "../../databases/db46/buildlink3.mk"
#.endif

# .if !empty(PKG_OPTIONS:Mpgsql)
# CONFIGURE_ARGS+=       --with-module=postgresql
# .  include "../../mk/pgsql.buildlink3.mk"
# .endif

# .if !empty(PKG_OPTIONS:Mgdbm)
# CONFIGURE_ARGS+=       --with-module=gdbm
# .  include "../../databases/gdbm/buildlink3.mk"
# .endif

# .if !empty(PKG_OPTIONS:Mpcre)
# CONFIGURE_ARGS+=       --with-module=pcre
# .  include "../../devel/pcre/buildlink3.mk"
# .endif

# .if !empty(PKG_OPTIONS:Mrawsock)
# CONFIGURE_ARGS+=       --with-module=rawsock
# .endif

# .if !empty(PKG_OPTIONS:Mfastcgi)
# CONFIGURE_ARGS+=       --with-module=fastcgi
# .  include "../../www/fcgi/buildlink3.mk"
# .endif

# .if !empty(PKG_OPTIONS:Mgtk2)
# CONFIGURE_ARGS+=       --with-module=gtk2
# .  include "../../devel/libglade/buildlink3.mk"
# .  include "../../x11/gtk2/buildlink3.mk"
# .endif

# .if !empty(PKG_OPTIONS:Mzlib)
# CONFIGURE_ARGS+=       --with-module=zlib
# BUILDLINK_API_DEPENDS.zlib+=   zlib>=1.2
# .include "../../devel/zlib/buildlink3.mk"
# .endif

## libffcall is required for some other options to work:
# .if !empty(PKG_OPTIONS:Mpgsql) && empty(PKG_OPTIONS:Mffcall)
# PKG_OPTIONS+=  ffcall
# .endif
