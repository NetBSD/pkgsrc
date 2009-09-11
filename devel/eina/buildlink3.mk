# $NetBSD: buildlink3.mk,v 1.2 2009/09/11 20:20:18 joerg Exp $

BUILDLINK_TREE+=	eina

.if !defined(EINA_BUILDLINK3_MK)
EINA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eina+=	eina>=0.0.2.062
BUILDLINK_PKGSRCDIR.eina?=	../../devel/eina
.endif	# EINA_BUILDLINK3_MK

BUILDLINK_TREE+=	-eina
