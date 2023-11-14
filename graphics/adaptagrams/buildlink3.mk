# $NetBSD: buildlink3.mk,v 1.5 2023/11/14 14:01:58 wiz Exp $

BUILDLINK_TREE+=	adaptagrams

.if !defined(ADAPTAGRAMS_BUILDLINK3_MK)
ADAPTAGRAMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adaptagrams+=	adaptagrams>=0.20160901nb1
BUILDLINK_ABI_DEPENDS.adaptagrams?=	adaptagrams>=0.20160901nb5
BUILDLINK_PKGSRCDIR.adaptagrams?=	../../graphics/adaptagrams

.include "../../graphics/cairomm/buildlink3.mk"
.endif	# ADAPTAGRAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-adaptagrams
