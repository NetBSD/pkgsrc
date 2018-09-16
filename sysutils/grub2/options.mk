# $NetBSD: options.mk,v 1.3 2018/09/16 13:18:54 triaxx Exp $
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

UNIFONT=		unifont-5.1.20080820.pcf
SITES.${UNIFONT}.gz=	http://unifoundry.com/

post-extract: do-move-unifont
.PHONY: do-move-unifont

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
DISTFILES+=		${UNIFONT}.gz
BUILD_DEPENDS+=		dejavu-ttf>=2.34nb1:../../fonts/dejavu-ttf
do-move-unifont:
	${MV} ${WRKDIR}/${UNIFONT} ${WRKSRC}/unifont.pcf
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-grub-mkfont
do-move-unifont:
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
