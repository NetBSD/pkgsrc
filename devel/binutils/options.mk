# $NetBSD: options.mk,v 1.2 2026/10/12 09:10:08 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.binutils
PKG_SUPPORTED_OPTIONS=	disable-ld nls

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
.if ${PKG_OPTIONS:Mdisable-ld}
CONFIGURE_ARGS+=	--disable-ld
.else
PLIST.gld=		yes
.endif

.if ${PKG_OPTIONS:Mnls}
PREFER.gettext=		pkgsrc
USE_TOOLS+=		msgfmt msgmerge xgettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SRC+=		PLIST.nls
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
