# $NetBSD: buildlink3.mk,v 1.40 2026/01/07 08:48:40 wiz Exp $

BUILDLINK_TREE+=	gpgmepp

.if !defined(GPGMEPP_BUILDLINK3_MK)
GPGMEPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgmepp+=	gpgmepp>=15.12.2
BUILDLINK_ABI_DEPENDS.gpgmepp?=	gpgmepp>=15.12.2nb42
BUILDLINK_PKGSRCDIR.gpgmepp?=	../../security/gpgmepp

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# GPGMEPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgmepp
