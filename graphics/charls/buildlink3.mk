# $NetBSD: buildlink3.mk,v 1.1 2021/02/14 11:51:57 nros Exp $

BUILDLINK_TREE+=	charls

.if !defined(CHARLS_BUILDLINK3_MK)
CHARLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.charls+=	charls>=2.2.0
BUILDLINK_PKGSRCDIR.charls?=	../../graphics/charls
.endif	# CHARLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-charls
