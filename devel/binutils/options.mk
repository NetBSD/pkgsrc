# $NetBSD: options.mk,v 1.1 2021/01/29 13:10:34 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.binutils
PKG_SUPPORTED_OPTIONS=	disable-ld

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS=	disable-ld
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gld

#
# Disable ld completely.  With the introduction of "libdep.so" this may now be
# required on some systems to avoid a dependency on libgcc.
#
.if !empty(PKG_OPTIONS:Mdisable-ld)
CONFIGURE_ARGS+=	--disable-ld
.else
PLIST.gld=		yes
.endif
