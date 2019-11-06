# $NetBSD: buildlink3.mk,v 1.1 2019/11/06 10:11:41 he Exp $

BUILDLINK_TREE+=	softhsm2

.if !defined(SOFTHSM2_BUILDLINK3_MK)
SOFTHSM2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.softhsm2+=	softhsm2>=2.0.0
BUILDLINK_ABI_DEPENDS.softhsm2+=	softhsm2>=2.0.0
BUILDLINK_PKGSRCDIR.softhsm2?=	../../security/softhsm2

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.endif	# SOFTHSM2_BUILDLINK3_MK

BUILDLINK_TREE+=	-softhsm2
