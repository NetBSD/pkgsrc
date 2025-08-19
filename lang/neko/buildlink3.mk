# $NetBSD: buildlink3.mk,v 1.2 2025/08/19 13:47:35 wiz Exp $

BUILDLINK_TREE+=	neko

.if !defined(NEKO_BUILDLINK3_MK)
NEKO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.neko+=	neko>=2.3.0
BUILDLINK_PKGSRCDIR.neko?=	../../lang/neko
.endif	# NEKO_BUILDLINK3_MK

BUILDLINK_TREE+=	-neko
