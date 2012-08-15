# $NetBSD: buildlink3.mk,v 1.1 2012/08/15 21:18:13 jmmv Exp $

BUILDLINK_TREE+=	shtk

.if !defined(SHTK_BUILDLINK3_MK)
SHTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shtk+=	shtk>=1.0
BUILDLINK_PKGSRCDIR.shtk?=	../../devel/shtk
.endif	# SHTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-shtk
