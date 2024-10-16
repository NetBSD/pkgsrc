# $NetBSD: buildlink3.mk,v 1.35 2024/08/09 09:42:33 ryoon Exp $

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
DEPENDS+=		gnupg2>=2.2.0:../../security/gnupg2
GPGME_GPG=		${PREFIX}/bin/gpg2
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
GPGME_GPG=		${PREFIX}/bin/gpg
.endif
.if ${GNU_CONFIGURE:U""} == "yes"
CONFIGURE_ARGS+=	ac_cv_path_GNUPG=${GPGME_GPG}
.endif

.endif # GPGME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpgme
