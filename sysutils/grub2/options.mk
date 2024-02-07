# $NetBSD: options.mk,v 1.6 2024/02/07 17:50:45 wiz Exp $
#

#
# Description of options (taken from configure --help):
# debug			include memory manager debugging
# freetype		build and install the `grub-mkfont' utility
# fuse			build and install the `grub-mount' utility
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.grub2
PKG_SUPPORTED_OPTIONS=	debug freetype fuse grub-efi
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
TOOL_DEPENDS+=		dejavu-ttf>=2.34nb1:../../fonts/dejavu-ttf
TOOL_DEPENDS+=		unifont-[0-9]*:../../fonts/unifont
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

#
# The configure script sets the variables `target_cpu' and `platform', which
# are used for the location of the library directory.  The following mimics
# the configure script's behavior for i386 and x86_64.
#
GRUB_TARGET_CPU=	${MACHINE_ARCH}
.if ${LOWER_VENDOR} == "apple" || !empty(PKG_OPTIONS:Mgrub-efi)
GRUB_PLATFORM=		efi
.else
.  if !defined(GRUB_PLATFORM)
GRUB_PLATFORM=		pc
.  endif
.endif
.if ${GRUB_TARGET_CPU} == "x86_64" && ${GRUB_PLATFORM} == "pc"
GRUB_TARGET_CPU=	i386
.endif
PLIST_SUBST+=		GRUB_TARGET_CPU=${GRUB_TARGET_CPU}
PLIST_SUBST+=		GRUB_PLATFORM=${GRUB_PLATFORM}
PLIST_VARS+=		efi
PLIST_VARS+=		pc
PLIST.${GRUB_PLATFORM}=	yes
