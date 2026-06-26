# $NetBSD: buildlink3.mk,v 1.43 2026/06/26 07:24:52 wiz Exp $

BUILDLINK_TREE+=	gpgmepp

.if !defined(GPGMEPP_BUILDLINK3_MK)
GPGMEPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgmepp+=	gpgmepp>=2.0.0<15
BUILDLINK_PKGSRCDIR.gpgmepp?=	../../security/gpgmepp

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.endif	# GPGMEPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgmepp
