# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/02 07:27:58 xtraeme Exp $
#
# This Makefile fragment is included by packages that use loudmouth.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(LOUDMOUTH_BUILDLINK2_MK)
LOUDMOUTH_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			loudmouth
BUILDLINK_DEPENDS.loudmouth?=		loudmouth>=0.10.1
BUILDLINK_PKGSRCDIR.loudmouth?=		../../devel/loudmouth

EVAL_PREFIX+=	BUILDLINK_PREFIX.loudmouth=loudmouth
BUILDLINK_PREFIX.loudmouth_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.loudmouth+=	include/loudmouth-1.0/loudmouth/*.h
BUILDLINK_FILES.loudmouth+=	lib/libloudmouth.*
BUILDLINK_FILES.loudmouth+=	lib/pkgconfig/loudmouth-1.0.pc

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

BUILDLINK_TARGETS+=	loudmouth-buildlink

loudmouth-buildlink: _BUILDLINK_USE

.endif	# LOUDMOUTH_BUILDLINK2_MK
