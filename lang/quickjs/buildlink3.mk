# $NetBSD: buildlink3.mk,v 1.4 2026/03/10 17:24:10 osa Exp $

BUILDLINK_TREE+=	quickjs

.if !defined(QUICKJS_BUILDLINK3_MK)
QUICKJS_BUILDLINK3_MK:=

BUILDLINK_INCDIRS.quickjs?=	include/quickjs

BUILDLINK_API_DEPENDS.quickjs+=	quickjs>=20250913
BUILDLINK_PKGSRCDIR.quickjs?=	../../lang/quickjs
.endif	# QUICKJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-quickjs
