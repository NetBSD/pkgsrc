# $NetBSD: buildlink3.mk,v 1.1 2016/09/18 23:36:00 kamil Exp $

BUILDLINK_TREE+=	adaptagrams

.if !defined(ADAPTAGRAMS_BUILDLINK3_MK)
ADAPTAGRAMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.adaptagrams+=	adaptagrams>=0.20160901
BUILDLINK_PKGSRCDIR.adaptagrams?=	../../graphics/adaptagrams
.endif	# ADAPTAGRAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-adaptagrams
