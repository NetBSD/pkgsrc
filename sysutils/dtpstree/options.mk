# $NetBSD: options.mk,v 1.1.1.1 2010/08/15 09:07:11 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.dtpstree
PKG_SUPPORTED_OPTIONS=	terminfo

CHECK_BUILTIN.terminfo:=	yes
.include "../../mk/terminfo.builtin.mk"
CHECK_BUILTIN.terminfo:=	no
.if !empty(CHECK_BUILTIN.terminfo:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS=	terminfo
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mterminfo)
.include "../../mk/terminfo.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-terminfo
.include "../../mk/termcap.buildlink3.mk"
.endif
