# $NetBSD: hacks.mk,v 1.1 2021/07/11 04:08:06 markd Exp $

.if !defined(FREEIMAGE_HACKS_MK)
FREEIMAGE_HACKS_MK=	defined

###
### For some reason on Linux PluginTIFF.cpp extracts with CR LF
### so strip CR before patch is applied.
###
.if ${OPSYS} == "Linux"
PKG_HACKS+=		strip-cr

SUBST_CLASSES+=		cr
SUBST_STAGE.cr=		pre-patch
SUBST_FILES.cr=		Source/FreeImage/PluginTIFF.cpp
SUBST_SED.cr=		-e 's|\r||'
.endif

.endif	# FREEIMAGE_HACKS_MK
