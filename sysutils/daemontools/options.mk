# $NetBSD: options.mk,v 1.1 2017/10/03 00:21:44 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.daemontools
PKG_SUPPORTED_OPTIONS+=		daemontools-moresignals
PKG_SUGGESTED_OPTIONS+=		daemontools-moresignals

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdaemontools-moresignals)
MORESIGNALS_PATCH=		daemontools-0.76.sigq12.patch
PATCHFILES+=			${MORESIGNALS_PATCH}
SITES.${MORESIGNALS_PATCH}=	http://thedjbway.b0llix.net/patches/
PATCH_DIST_STRIP.${MORESIGNALS_PATCH}=	-p1
.endif
