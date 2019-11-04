# $NetBSD: options.mk,v 1.2 2019/11/04 21:28:43 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.daemontools
PKG_SUPPORTED_OPTIONS+=		daemontools-moresignals
PKG_SUGGESTED_OPTIONS+=		daemontools-moresignals

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdaemontools-moresignals)
MORESIGNALS_PATCH=			daemontools-0.76.sigq12.patch
PATCHFILES+=				${MORESIGNALS_PATCH}
SITES.${MORESIGNALS_PATCH}=		http://thedjbway.b0llix.net/patches/
PATCH_DIST_STRIP.${MORESIGNALS_PATCH}=	-p1
.endif
