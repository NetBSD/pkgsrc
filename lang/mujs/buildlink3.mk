# $NetBSD: buildlink3.mk,v 1.2 2023/04/24 07:50:40 wiz Exp $

BUILDLINK_TREE+=	mujs

.if !defined(MUJS_BUILDLINK3_MK)
MUJS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.mujs?=	build

BUILDLINK_API_DEPENDS.mujs+=	mujs>=1.3.3
BUILDLINK_PKGSRCDIR.mujs?=	../../lang/mujs
.endif	# MUJS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mujs
