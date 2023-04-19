# $NetBSD: buildlink3.mk,v 1.27 2023/04/19 08:08:42 adam Exp $

BUILDLINK_TREE+=	softhsm

.if !defined(SOFTHSM_BUILDLINK3_MK)
SOFTHSM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.softhsm+=	softhsm>=1.1.3
BUILDLINK_ABI_DEPENDS.softhsm+=	softhsm>=1.3.7nb23
BUILDLINK_PKGSRCDIR.softhsm?=	../../security/softhsm

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/botan1/buildlink3.mk"
.endif	# SOFTHSM_BUILDLINK3_MK

BUILDLINK_TREE+=	-softhsm
