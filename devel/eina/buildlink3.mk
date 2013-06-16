# $NetBSD: buildlink3.mk,v 1.4 2013/06/16 18:56:04 sno Exp $

BUILDLINK_TREE+=	eina

.if !defined(EINA_BUILDLINK3_MK)
EINA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eina+=	eina>=1.7.7
BUILDLINK_PKGSRCDIR.eina?=	../../devel/eina
.endif	# EINA_BUILDLINK3_MK

BUILDLINK_TREE+=	-eina
