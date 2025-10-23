# $NetBSD: buildlink3.mk,v 1.7 2025/10/23 20:37:22 wiz Exp $

BUILDLINK_TREE+=	adaptagrams

.if !defined(ADAPTAGRAMS_BUILDLINK3_MK)
ADAPTAGRAMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adaptagrams+=	adaptagrams>=0.20160901nb1
BUILDLINK_ABI_DEPENDS.adaptagrams?=	adaptagrams>=0.20231102nb2
BUILDLINK_PKGSRCDIR.adaptagrams?=	../../graphics/adaptagrams

.include "../../graphics/cairomm/buildlink3.mk"
.endif	# ADAPTAGRAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-adaptagrams
