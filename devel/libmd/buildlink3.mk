# $NetBSD: buildlink3.mk,v 1.1 2022/12/19 15:08:04 vins Exp $

BUILDLINK_TREE+=	libmd

.if !defined(LIBMD_BUILDLINK3_MK)
LIBMD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmd+=	libmd>=1.0.4
BUILDLINK_PKGSRCDIR.libmd?=	../../devel/libmd
.endif	# LIBMD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmd
