# $NetBSD: options.mk,v 1.19 2026/07/26 17:49:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.groff
PKG_SUPPORTED_OPTIONS=	groff-docs uchardet x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgroff-docs)
# Consequently, groff's HTML output driver, 'grohtml', will not work
# properly.  It will not be possible to prepare or install
# groff-generated documentation in HTML format.
USE_TOOLS+=		gs:run
PLIST_SRC+=		PLIST.docs
DEPENDS+=		netpbm>=10.0:../../graphics/netpbm
.else
CONFIGURE_ARGS+=	--without-gs
.endif

.if !empty(PKG_OPTIONS:Muchardet)
# The 'preconv' preprocessor program will be unable to attempt automatic
# inference of an input file's character encoding.  See the preconv(1)
# man page.
.include "../../textproc/uchardet/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-appresdir=${PREFIX}/lib/X11/app-defaults
PLIST_SRC+=		PLIST.x11
.include "../../mk/xaw.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
