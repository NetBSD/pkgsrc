# $NetBSD: buildlink2.mk,v 1.5 2003/12/21 10:17:30 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnutls.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(GNUTLS_BUILDLINK2_MK)
GNUTLS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnutls
BUILDLINK_DEPENDS.gnutls?=		gnutls>=1.0.1
BUILDLINK_PKGSRCDIR.gnutls?=		../../security/gnutls

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnutls=gnutls
BUILDLINK_PREFIX.gnutls_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnutls+=	include/gnutls/*.h
BUILDLINK_FILES.gnutls+=	lib/libgnutls-extra.*
BUILDLINK_FILES.gnutls+=	lib/libgnutls-openssl.*
BUILDLINK_FILES.gnutls+=	lib/libgnutls.*

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"
.include "../../security/libtasn1/buildlink2.mk"
.include "../../security/opencdk/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	gnutls-buildlink

gnutls-buildlink: _BUILDLINK_USE

.endif	# GNUTLS_BUILDLINK2_MK
