# $NetBSD: buildlink2.mk,v 1.4 2003/05/02 11:55:34 wiz Exp $

.if !defined(UNICON_IM_BUILDLINK2_MK)
UNICON_IM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			unicon-im
BUILDLINK_DEPENDS.unicon-im?=		unicon-im>=1.2nb2
BUILDLINK_PKGSRCDIR.unicon-im?=		../../inputmethod/unicon-im

EVAL_PREFIX+=	BUILDLINK_PREFIX.unicon-im=unicon-im
BUILDLINK_PREFIX.unicon-im_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.unicon-im+=	lib/libimm_server.*
BUILDLINK_FILES.unicon-im+=	lib/libimmclient.*
BUILDLINK_FILES.unicon-im+=	lib/unicon/TL_hzinput.*
BUILDLINK_FILES.unicon-im+=	lib/unicon/cce_hzinput.*
BUILDLINK_FILES.unicon-im+=	lib/unicon/cce_pinyin.*

.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=	unicon-im-buildlink

unicon-im-buildlink: _BUILDLINK_USE

.endif	# UNICON_IM_BUILDLINK2_MK
