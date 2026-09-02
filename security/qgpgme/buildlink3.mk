# $NetBSD: buildlink3.mk,v 1.37 2026/09/02 19:04:21 wiz Exp $

BUILDLINK_TREE+=	qgpgme

.if !defined(QGPGME_BUILDLINK3_MK)
QGPGME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qgpgme+=	qgpgme>=1.10.0
BUILDLINK_ABI_DEPENDS.qgpgme?=	qgpgme>=2.0.0nb3
BUILDLINK_PKGSRCDIR.qgpgme?=	../../security/qgpgme

.include "../../security/gpgme/buildlink3.mk"
.include "../../security/gpgmepp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QGPGME_BUILDLINK3_MK

BUILDLINK_TREE+=	-qgpgme
