# $NetBSD: buildlink3.mk,v 1.34 2026/01/31 08:04:30 markd Exp $

BUILDLINK_TREE+=	qgpgme

.if !defined(QGPGME_BUILDLINK3_MK)
QGPGME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qgpgme+=	qgpgme>=1.10.0
BUILDLINK_ABI_DEPENDS.qgpgme?=	qgpgme>=1.24.3nb1
BUILDLINK_PKGSRCDIR.qgpgme?=	../../security/qgpgme

.include "../../security/gpgme/buildlink3.mk"
.include "../../security/gpgmepp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QGPGME_BUILDLINK3_MK

BUILDLINK_TREE+=	-qgpgme
