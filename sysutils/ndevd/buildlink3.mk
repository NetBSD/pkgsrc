# $NetBSD: buildlink3.mk,v 1.1 2025/12/30 11:06:20 kikadf Exp $

BUILDLINK_TREE+=	ndevd

.if !defined(NDEVD_BUILDLINK3_MK)
NDEVD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ndevd+=	ndevd>=25.12.09
BUILDLINK_ABI_DEPENDS.ndevd+=	ndevd>=25.12.09
BUILDLINK_PKGSRCDIR.ndevd?=	../../sysutils/ndevd

.endif # NDEVD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ndevd
