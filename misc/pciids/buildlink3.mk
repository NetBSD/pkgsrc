# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:01 joerg Exp $

BUILDLINK_TREE+=	pciids

.if !defined(PCIIDS_BUILDLINK3_MK)
PCIIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pciids+=	pciids>=20061026
BUILDLINK_PKGSRCDIR.pciids?=	../../misc/pciids
.endif # PCIIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pciids
