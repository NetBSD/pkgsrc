# $NetBSD: buildlink3.mk,v 1.3 2011/12/05 17:14:52 joerg Exp $

BUILDLINK_TREE+=	eina

.if !defined(EINA_BUILDLINK3_MK)
EINA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eina+=	eina>=1.1.0
BUILDLINK_PKGSRCDIR.eina?=	../../devel/eina
.endif	# EINA_BUILDLINK3_MK

BUILDLINK_TREE+=	-eina
