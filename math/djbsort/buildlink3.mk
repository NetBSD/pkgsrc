# $NetBSD: buildlink3.mk,v 1.2 2018/07/31 05:38:56 schmonz Exp $

BUILDLINK_TREE+=	djbsort

.if !defined(DJBSORT_BUILDLINK3_MK)
DJBSORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.djbsort+=	djbsort>=20180717
BUILDLINK_PKGSRCDIR.djbsort?=	../../math/djbsort
BUILDLINK_DEPMETHOD.djbsort?=	build
BUILDLINK_FILES_CMD.djbsort=	${CAT} ${BUILDLINK_PREFIX.djbsort}/share/djbsort/pseudo-PLIST
.endif	# DJBSORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-djbsort
