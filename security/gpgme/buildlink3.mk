# $NetBSD: buildlink3.mk,v 1.17 2009/03/20 19:25:17 joerg Exp $

BUILDLINK_TREE+=	gpgme

.if !defined(GPGME_BUILDLINK3_MK)
GPGME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=0.9.0
BUILDLINK_ABI_DEPENDS.gpgme+=	gpgme>=1.0.3nb1
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../devel/librfuncs/buildlink3.mk"
.endif # GPGME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgme
