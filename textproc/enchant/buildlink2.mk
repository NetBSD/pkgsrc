# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/17 21:11:35 wiz Exp $
#
# This Makefile fragment is included by packages that use enchant.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(ENCHANT_BUILDLINK2_MK)
ENCHANT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			enchant
BUILDLINK_DEPENDS.enchant?=		enchant>=0.4.0
BUILDLINK_PKGSRCDIR.enchant?=		../../textproc/enchant

EVAL_PREFIX+=	BUILDLINK_PREFIX.enchant=enchant
BUILDLINK_PREFIX.enchant_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.enchant+=	include/enchant/enchant++.h
BUILDLINK_FILES.enchant+=	include/enchant/enchant-provider.h
BUILDLINK_FILES.enchant+=	include/enchant/enchant.h
BUILDLINK_FILES.enchant+=	lib/enchant/libenchant_aspell.*
BUILDLINK_FILES.enchant+=	lib/enchant/libenchant_ispell.*
BUILDLINK_FILES.enchant+=	lib/enchant/libenchant_myspell.*
BUILDLINK_FILES.enchant+=	lib/libenchant.*
BUILDLINK_FILES.enchant+=	lib/pkgconfig/enchant.pc

.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"

BUILDLINK_TARGETS+=	enchant-buildlink

enchant-buildlink: _BUILDLINK_USE

.endif	# ENCHANT_BUILDLINK2_MK
