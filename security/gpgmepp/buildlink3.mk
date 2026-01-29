# $NetBSD: buildlink3.mk,v 1.42 2026/01/29 13:55:23 wiz Exp $

BUILDLINK_TREE+=	gpgmepp

.if !defined(GPGMEPP_BUILDLINK3_MK)
GPGMEPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgmepp+=	gpgmepp>=2.0.0
BUILDLINK_PKGSRCDIR.gpgmepp?=	../../security/gpgmepp

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.endif	# GPGMEPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgmepp
