# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:01 wiz Exp $

BUILDLINK_TREE+=	libmicrodns

.if !defined(LIBMICRODNS_BUILDLINK3_MK)
LIBMICRODNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmicrodns+=	libmicrodns>=0.2.0
BUILDLINK_ABI_DEPENDS.libmicrodns?=	libmicrodns>=0.2.0nb1
BUILDLINK_PKGSRCDIR.libmicrodns?=	../../net/libmicrodns
.endif	# LIBMICRODNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmicrodns
