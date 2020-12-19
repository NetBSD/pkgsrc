# $NetBSD: buildlink3.mk,v 1.1 2020/12/19 10:22:45 nia Exp $

BUILDLINK_TREE+=	libcue

.if !defined(LIBCUE_BUILDLINK3_MK)
LIBCUE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcue+=	libcue>=2.2.1
BUILDLINK_PKGSRCDIR.libcue?=	../../textproc/libcue
.endif	# LIBCUE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcue
