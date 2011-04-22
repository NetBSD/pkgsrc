# $NetBSD: buildlink3.mk,v 1.20 2011/04/22 13:42:47 obache Exp $

BUILDLINK_TREE+=	gpgme

.if !defined(GPGME_BUILDLINK3_MK)
GPGME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=0.9.0
BUILDLINK_ABI_DEPENDS.gpgme+=	gpgme>=1.3.0nb1
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme

.include "../../devel/librfuncs/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"

pkgbase:=		gpgme
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gpgme:Mgpgsm)
GPGME_GPG=		${PREFIX}/bin/gpg2
.else
GPGME_GPG=		${PREFIX}/bin/gpg
.endif

.endif # GPGME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgme
