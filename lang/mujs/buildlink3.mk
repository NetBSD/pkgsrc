# $NetBSD: buildlink3.mk,v 1.1 2022/08/30 12:47:02 nia Exp $

BUILDLINK_TREE+=	mujs

.if !defined(MUJS_BUILDLINK3_MK)
MUJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mujs+=	mujs>=1.2.0
BUILDLINK_PKGSRCDIR.mujs?=	../../lang/mujs
.endif	# MUJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mujs
