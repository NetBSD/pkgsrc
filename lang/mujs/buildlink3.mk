# $NetBSD: buildlink3.mk,v 1.3 2023/09/10 09:36:38 nia Exp $

BUILDLINK_TREE+=	mujs

.if !defined(MUJS_BUILDLINK3_MK)
MUJS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mujs+=	mujs>=1.3.3
BUILDLINK_PKGSRCDIR.mujs?=	../../lang/mujs
.endif	# MUJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mujs
