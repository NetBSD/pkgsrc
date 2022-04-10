# $NetBSD: avoid-duplicate.mk,v 1.4 2022/04/10 08:52:01 nia Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "native"
.  if !empty(X11_BIN_NAME)
.    if exists(${X11BASE}/bin/${X11_BIN_NAME})
PKG_SKIP_REASON+=	"Package set is using native X11 component"
.    endif
.  elif !empty(X11_LIB_NAME)
.    if exists(${X11BASE}/lib/${X11_LIB_NAME}.so)
PKG_SKIP_REASON+=	"Package set is using native X11 component"
.    endif
.  elif !empty(X11_DRV_NAME)
.    if exists(${X11BASE}/lib/modules/drivers/${X11_DRV_NAME}_drv.so)
PKG_SKIP_REASON+=	"Package set is using native X11 component"
.    endif
.  endif
.endif
