# $NetBSD: buildlink2.mk,v 1.2 2003/10/18 08:10:57 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnutls.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GNUTLS_BUILDLINK2_MK)
GNUTLS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnutls
BUILDLINK_DEPENDS.gnutls?=		gnutls>=0.8.7nb1
BUILDLINK_PKGSRCDIR.gnutls?=		../../security/gnutls

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnutls=gnutls
BUILDLINK_PREFIX.gnutls_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnutls+=	include/gnutls/*.h
BUILDLINK_FILES.gnutls+=	lib/libgnutls-extra.*
BUILDLINK_FILES.gnutls+=	lib/libgnutls.*

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/opencdk/buildlink2.mk"

BUILDLINK_TARGETS+=	gnutls-buildlink

gnutls-buildlink: _BUILDLINK_USE

.endif	# GNUTLS_BUILDLINK2_MK
