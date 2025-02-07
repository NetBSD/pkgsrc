# $NetBSD: buildlink3.mk,v 1.2 2025/02/07 12:20:38 pho Exp $

BUILDLINK_TREE+=	quickjs

.if !defined(QUICKJS_BUILDLINK3_MK)
QUICKJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.quickjs+=	quickjs>=20210327nb3
BUILDLINK_PKGSRCDIR.quickjs?=	../../lang/quickjs
.endif	# QUICKJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-quickjs
