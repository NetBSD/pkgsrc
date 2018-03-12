# $NetBSD: buildlink3.mk,v 1.9 2018/03/12 11:15:43 wiz Exp $

BUILDLINK_TREE+=	gpgmepp

.if !defined(GPGMEPP_BUILDLINK3_MK)
GPGMEPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgmepp+=	gpgmepp>=15.12.2
BUILDLINK_ABI_DEPENDS.gpgmepp?=	gpgmepp>=15.12.2nb8
BUILDLINK_PKGSRCDIR.gpgmepp?=	../../security/gpgmepp

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# GPGMEPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgmepp
