# $NetBSD: buildlink2.mk,v 1.2 2002/09/23 02:02:46 jlam Exp $

.if !defined(UNICON_IM_BUILDLINK2_MK)
UNICON_IM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			unicon-im
BUILDLINK_DEPENDS.unicon-im?=		unicon-im>=1.2
BUILDLINK_PKGSRCDIR.unicon-im?=		../../inputmethod/unicon-im

EVAL_PREFIX+=	BUILDLINK_PREFIX.unicon-im=unicon-im
BUILDLINK_PREFIX.unicon-im_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.unicon-im+=	lib/libimm_server.*
BUILDLINK_FILES.unicon-im+=	lib/libimmclient.*
BUILDLINK_FILES.unicon-im+=	lib/unicon/TL_hzinput.*
BUILDLINK_FILES.unicon-im+=	lib/unicon/cce_hzinput.*
BUILDLINK_FILES.unicon-im+=	lib/unicon/cce_pinyin.*

.include "../../devel/pth/buildlink2.mk"

BUILDLINK_TARGETS+=	unicon-im-buildlink

unicon-im-buildlink: _BUILDLINK_USE

.endif	# UNICON_IM_BUILDLINK2_MK
