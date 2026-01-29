# $NetBSD: buildlink3.mk,v 1.37 2026/01/29 10:03:12 wiz Exp $

BUILDLINK_TREE+=	gpgme

.if !defined(GPGME_BUILDLINK3_MK)
GPGME_BUILDLINK3_MK:=

USE_CXX_FEATURES+=		c++11

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=0.9.0
BUILDLINK_ABI_DEPENDS.gpgme+=	gpgme>=1.23.2nb1
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme

.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"

pkgbase:=		gpgme
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gpgme:Mgnupg2}
DEPENDS+=		gnupg2>=2.4.9nb2:../../security/gnupg2
GPGME_GPG=		${PREFIX}/bin/gpg
.else
DEPENDS+=		gnupg>=1.4.23nb28:../../security/gnupg
GPGME_GPG=		${PREFIX}/bin/gpg1
.endif
.if ${GNU_CONFIGURE:U""} == "yes"
CONFIGURE_ARGS+=	ac_cv_path_GNUPG=${GPGME_GPG}
.endif

.endif # GPGME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgme
