# $NetBSD: buildlink3.mk,v 1.1 2012/03/19 21:28:53 markd Exp $

BUILDLINK_TREE+=	kdesdk4

.if !defined(KDESDK4_BUILDLINK3_MK)
KDESDK4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdesdk4+=	kdesdk4>=4.6.2
BUILDLINK_PKGSRCDIR.kdesdk4?=	../../devel/kdesdk4

.endif	# KDESDK4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdesdk4
