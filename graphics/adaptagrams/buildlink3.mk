# $NetBSD: buildlink3.mk,v 1.4 2023/11/12 13:21:50 wiz Exp $

BUILDLINK_TREE+=	adaptagrams

.if !defined(ADAPTAGRAMS_BUILDLINK3_MK)
ADAPTAGRAMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adaptagrams+=	adaptagrams>=0.20160901nb1
BUILDLINK_ABI_DEPENDS.adaptagrams?=	adaptagrams>=0.20160901nb4
BUILDLINK_PKGSRCDIR.adaptagrams?=	../../graphics/adaptagrams

.include "../../graphics/cairomm/buildlink3.mk"
.endif	# ADAPTAGRAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-adaptagrams
