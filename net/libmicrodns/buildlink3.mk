# $NetBSD: buildlink3.mk,v 1.1 2021/02/11 14:43:32 ryoon Exp $

BUILDLINK_TREE+=	libmicrodns

.if !defined(LIBMICRODNS_BUILDLINK3_MK)
LIBMICRODNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmicrodns+=	libmicrodns>=0.2.0
BUILDLINK_PKGSRCDIR.libmicrodns?=	../../net/libmicrodns
.endif	# LIBMICRODNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmicrodns
