# $NetBSD: buildlink3.mk,v 1.3 2023/10/02 20:03:25 nros Exp $

BUILDLINK_TREE+=	charls

.if !defined(CHARLS_BUILDLINK3_MK)
CHARLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.charls+=	charls>=2.2.0
BUILDLINK_ABI_DEPENDS.charls?=	charls>=2.4.2
BUILDLINK_PKGSRCDIR.charls?=	../../graphics/charls
.endif	# CHARLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-charls
