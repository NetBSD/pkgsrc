# $NetBSD: buildlink3.mk,v 1.25 2017/03/31 10:31:57 wiz Exp $

BUILDLINK_TREE+=	gpgme

.if !defined(GPGME_BUILDLINK3_MK)
GPGME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=0.9.0
BUILDLINK_ABI_DEPENDS.gpgme+=	gpgme>=1.8.0
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme

.include "../../devel/librfuncs/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"

pkgbase:=		gpgme
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gpgme:Mgnupg21)
DEPENDS+=		gnupg21>=2.1:../../security/gnupg21
GPGME_GPG=		${PREFIX}/bin/gpg2
.elif !empty(PKG_BUILD_OPTIONS.gpgme:Mgnupg2)
DEPENDS+=		gnupg2>=2.0<2.1:../../security/gnupg2
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
