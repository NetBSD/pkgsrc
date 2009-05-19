# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/05/19 17:26:28 minskim Exp $

BUILDLINK_TREE+=	eina

.if !defined(EINA_BUILDLINK3_MK)
EINA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eina+=	eina>=0.0.2.060
BUILDLINK_PKGSRCDIR.eina?=	../../devel/eina
.endif	# EINA_BUILDLINK3_MK

BUILDLINK_TREE+=	-eina
