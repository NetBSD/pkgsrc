# $NetBSD: buildlink3.mk,v 1.10 2018/04/14 07:34:00 adam Exp $

BUILDLINK_TREE+=	gpgmepp

.if !defined(GPGMEPP_BUILDLINK3_MK)
GPGMEPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgmepp+=	gpgmepp>=15.12.2
BUILDLINK_ABI_DEPENDS.gpgmepp?=	gpgmepp>=15.12.2nb9
BUILDLINK_PKGSRCDIR.gpgmepp?=	../../security/gpgmepp

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# GPGMEPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgmepp
