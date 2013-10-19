# $NetBSD: buildlink3.mk,v 1.7 2013/10/19 09:06:56 adam Exp $

BUILDLINK_TREE+=	softhsm

.if !defined(SOFTHSM_BUILDLINK3_MK)
SOFTHSM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.softhsm+=	softhsm>=1.1.3
BUILDLINK_ABI_DEPENDS.softhsm+=	softhsm>=1.3.5nb1
BUILDLINK_PKGSRCDIR.softhsm?=	../../security/softhsm

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.endif	# SOFTHSM_BUILDLINK3_MK

BUILDLINK_TREE+=	-softhsm
