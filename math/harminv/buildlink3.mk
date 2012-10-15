# $NetBSD: buildlink3.mk,v 1.1 2012/10/15 18:57:29 asau Exp $

BUILDLINK_TREE+=	harminv

.if !defined(HARMINV_BUILDLINK3_MK)
HARMINV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.harminv+=	harminv>=1.3.1
BUILDLINK_PKGSRCDIR.harminv?=	../../math/harminv

.endif	# HARMINV_BUILDLINK3_MK

BUILDLINK_TREE+=	-harminv
