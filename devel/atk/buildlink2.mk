# $NetBSD: buildlink2.mk,v 1.10 2004/04/01 18:13:48 jmmv Exp $
#
# This Makefile fragment is included by packages that use atk.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(ATK_BUILDLINK2_MK)
ATK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		atk
BUILDLINK_DEPENDS.atk?=		atk>=1.6.0
BUILDLINK_PKGSRCDIR.atk?=	../../devel/atk

EVAL_PREFIX+=		BUILDLINK_PREFIX.atk=atk
BUILDLINK_PREFIX.atk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.atk=	include/atk-1.0/*/*
BUILDLINK_FILES.atk+=	include/atk-1.0/*
BUILDLINK_FILES.atk+=	lib/libatk-1.0.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	atk-buildlink

atk-buildlink: _BUILDLINK_USE

.endif	# ATK_BUILDLINK2_MK
