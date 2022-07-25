# $NetBSD: buildlink3.mk,v 1.2 2022/07/25 11:04:45 wiz Exp $

BUILDLINK_TREE+=	adaptagrams

.if !defined(ADAPTAGRAMS_BUILDLINK3_MK)
ADAPTAGRAMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adaptagrams+=	adaptagrams>=0.20160901nb1
BUILDLINK_PKGSRCDIR.adaptagrams?=	../../graphics/adaptagrams

.include "../../graphics/cairomm/buildlink3.mk"
.endif	# ADAPTAGRAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-adaptagrams
