# $NetBSD: buildlink2.mk,v 1.8 2003/11/25 12:21:27 salo Exp $
#
# This Makefile fragment is included by packages that use atk.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(ATK_BUILDLINK2_MK)
ATK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		atk
BUILDLINK_DEPENDS.atk?=		atk>=1.2.2nb2
BUILDLINK_PKGSRCDIR.atk?=	../../devel/atk

EVAL_PREFIX+=		BUILDLINK_PREFIX.atk=atk
BUILDLINK_PREFIX.atk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.atk=	include/atk-1.0/*/*
BUILDLINK_FILES.atk+=	include/atk-1.0/*
BUILDLINK_FILES.atk+=	lib/libatk-1.0.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

BUILDLINK_TARGETS+=	atk-buildlink

atk-buildlink: _BUILDLINK_USE

.endif	# ATK_BUILDLINK2_MK
