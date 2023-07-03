# $NetBSD: buildlink3.mk,v 1.2 2023/07/03 10:51:40 vins Exp $

BUILDLINK_TREE+=	libmd

.if !defined(LIBMD_BUILDLINK3_MK)
LIBMD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmd+=	libmd>=1.1.0
BUILDLINK_PKGSRCDIR.libmd?=	../../devel/libmd
.endif	# LIBMD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmd
