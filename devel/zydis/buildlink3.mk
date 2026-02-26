# $NetBSD: buildlink3.mk,v 1.1 2026/02/26 22:55:54 alnsn Exp $

BUILDLINK_TREE+=	zydis

.if !defined(ZYDIS_BUILDLINK3_MK)
ZYDIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zydis+=	zydis>=4.1.1
BUILDLINK_ABI_DEPENDS.zydis+=	zydis>=4.1.1
BUILDLINK_PKGSRCDIR.zydis?=	../../devel/zydis

.include "../../devel/zycore-c/buildlink3.mk"
.endif	# ZYDIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-zydis
