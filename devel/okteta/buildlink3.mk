# $NetBSD: buildlink3.mk,v 1.2 2023/10/14 03:39:54 markd Exp $

BUILDLINK_TREE+=	okteta

.if !defined(OKTETA_BUILDLINK3_MK)
OKTETA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.okteta+=	okteta>=0.26.6
BUILDLINK_PKGSRCDIR.okteta?=	../../devel/okteta

.endif	# OKTETA_BUILDLINK3_MK

BUILDLINK_TREE+=	-okteta
