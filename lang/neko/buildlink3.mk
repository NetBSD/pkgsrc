# $NetBSD: buildlink3.mk,v 1.1 2020/03/24 13:23:46 nia Exp $

BUILDLINK_TREE+=	neko

.if !defined(NEKO_BUILDLINK3_MK)
NEKO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.neko+=	neko>=2.3.0
BUILDLINK_PKGSRCDIR.neko?=	../../mywip/neko
.endif	# NEKO_BUILDLINK3_MK

BUILDLINK_TREE+=	-neko
