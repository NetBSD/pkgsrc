# $NetBSD: buildlink3.mk,v 1.3 2025/02/07 12:36:23 pho Exp $

BUILDLINK_TREE+=	quickjs

.if !defined(QUICKJS_BUILDLINK3_MK)
QUICKJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.quickjs+=	quickjs>=20240113
BUILDLINK_PKGSRCDIR.quickjs?=	../../lang/quickjs
.endif	# QUICKJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-quickjs
