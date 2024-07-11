# $NetBSD: buildlink3.mk,v 1.1 2024/07/11 17:18:22 wiz Exp $

BUILDLINK_TREE+=	raqm

.if !defined(RAQM_BUILDLINK3_MK)
RAQM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raqm+=	raqm>=0.10.1
BUILDLINK_PKGSRCDIR.raqm?=	../../graphics/raqm

.endif	# RAQM_BUILDLINK3_MK

BUILDLINK_TREE+=	-raqm
