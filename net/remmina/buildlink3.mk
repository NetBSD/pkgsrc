# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:03 wiz Exp $

BUILDLINK_TREE+=	remmina

.if !defined(REMMINA_BUILDLINK3_MK)
REMMINA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.remmina+=	remmina>=0.9.3
BUILDLINK_ABI_DEPENDS.remmina?=	remmina>=1.4.29nb5
BUILDLINK_PKGSRCDIR.remmina?=	../../net/remmina

.endif	# REMMINA_BUILDLINK3_MK

BUILDLINK_TREE+=	-remmina
