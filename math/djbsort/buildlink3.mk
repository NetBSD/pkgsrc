# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:24:49 wiz Exp $

BUILDLINK_TREE+=	djbsort

.if !defined(DJBSORT_BUILDLINK3_MK)
DJBSORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.djbsort+=	djbsort>=20190516
BUILDLINK_ABI_DEPENDS.djbsort?=	djbsort>=20190516nb2
BUILDLINK_PKGSRCDIR.djbsort?=	../../math/djbsort
BUILDLINK_DEPMETHOD.djbsort?=	build
BUILDLINK_FILES_CMD.djbsort=	${CAT} ${BUILDLINK_PREFIX.djbsort}/share/djbsort/pseudo-PLIST
.endif	# DJBSORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-djbsort
