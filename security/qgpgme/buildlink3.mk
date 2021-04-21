# $NetBSD: buildlink3.mk,v 1.15 2021/04/21 11:40:37 adam Exp $

BUILDLINK_TREE+=	qgpgme

.if !defined(QGPGME_BUILDLINK3_MK)
QGPGME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qgpgme+=	qgpgme>=1.10.0
BUILDLINK_ABI_DEPENDS.qgpgme?=	qgpgme>=1.15.1nb1
BUILDLINK_PKGSRCDIR.qgpgme?=	../../security/qgpgme

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QGPGME_BUILDLINK3_MK

BUILDLINK_TREE+=	-qgpgme
