# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/07 07:25:55 agc Exp $

BUILDLINK_TREE+=	sfslite

.if !defined(SFSLITE_BUILDLINK3_MK)
SFSLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sfslite+=	sfslite>=1.2.7
BUILDLINK_PKGSRCDIR.sfslite?=	../../devel/sfslite

.endif	# SFSLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-sfslite
