# $NetBSD: buildlink3.mk,v 1.1 2026/04/13 15:49:39 kikadf Exp $

BUILDLINK_TREE+=	seatd

.if !defined(SEATD_BUILDLINK3_MK)
SEATD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seatd+=	seatd>=0.9.1
BUILDLINK_ABI_DEPENDS.seatd+=	seatd>=0.9.1
BUILDLINK_PKGSRCDIR.seatd?=	../../sysutils/seatd

.endif # SEATD_BUILDLINK3_MK

BUILDLINK_TREE+=	-seatd
