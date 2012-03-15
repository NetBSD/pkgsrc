# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/15 17:06:51 asau Exp $

BUILDLINK_TREE+=	remmina

.if !defined(REMMINA_BUILDLINK3_MK)
REMMINA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.remmina+=	remmina>=0.9.3
BUILDLINK_PKGSRCDIR.remmina?=	../../net/remmina

.endif	# REMMINA_BUILDLINK3_MK

BUILDLINK_TREE+=	-remmina
