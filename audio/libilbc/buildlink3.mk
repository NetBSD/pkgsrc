# $NetBSD: buildlink3.mk,v 1.1 2023/11/20 18:26:25 adam Exp $

BUILDLINK_TREE+=	libilbc

.if !defined(LIBILBC_BUILDLINK3_MK)
LIBILBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libilbc+=	libilbc>=3.0.4
BUILDLINK_PKGSRCDIR.libilbc?=	../../audio/libilbc
.endif	# LIBILBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libilbc
