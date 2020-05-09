# $NetBSD: options.mk,v 1.4 2020/05/09 12:17:52 triaxx Exp $
#

#
# Description of options (taken from configure --help):
# debug			include memory manager debugging
# freetype		build and install the `grub-mkfont' utility
# fuse			build and install the `grub-mount' utility
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.grub2
PKG_SUPPORTED_OPTIONS=	debug freetype fuse
PKG_SUGGESTED_OPTIONS=	freetype

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		freetype fuse

###
### debug support
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-mm-debug
.else
CONFIGURE_ARGS+=	--disable-mm-debug
.endif

###
### FreeType support
###
.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-grub-mkfont
PLIST.freetype=		yes
BUILD_DEPENDS+=		dejavu-ttf>=2.34nb1:../../fonts/dejavu-ttf
BUILD_DEPENDS+=		unifont-[0-9]*:../../fonts/unifont
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-grub-mkfont
.endif

###
### FUSE support
###
.if !empty(PKG_OPTIONS:Mfuse)
CONFIGURE_ARGS+=	--enable-grub-mount
PLIST.fuse=		yes
.include "../../filesystems/fuse/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-grub-mount
.endif
