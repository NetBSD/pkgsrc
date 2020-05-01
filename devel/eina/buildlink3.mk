# $NetBSD: buildlink3.mk,v 1.5 2020/05/01 00:01:32 joerg Exp $

BUILDLINK_TREE+=	eina

.if !defined(EINA_BUILDLINK3_MK)
EINA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eina+=	eina>=1.7.10
BUILDLINK_PKGSRCDIR.eina?=	../../devel/eina
.endif	# EINA_BUILDLINK3_MK

BUILDLINK_TREE+=	-eina
