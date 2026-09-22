# $NetBSD: buildlink3.mk,v 1.1 2026/09/22 08:20:33 ryoon Exp $

BUILDLINK_TREE+=	quickjs-ng

.if !defined(QUICKJS_NG_BUILDLINK3_MK)
QUICKJS_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.quickjs-ng+=	quickjs-ng>=0.16.2
BUILDLINK_PKGSRCDIR.quickjs-ng?=	../../lang/quickjs-ng
.endif	# QUICKJS_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-quickjs-ng
