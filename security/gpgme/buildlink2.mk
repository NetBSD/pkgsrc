# $NetBSD: buildlink2.mk,v 1.5 2003/12/14 15:05:01 wiz Exp $
#

.if !defined(GPGME_BUILDLINK2_MK)
GPGME_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gpgme
BUILDLINK_DEPENDS.gpgme?=	gpgme>=0.4.3
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme

EVAL_PREFIX+=		BUILDLINK_PREFIX.gpgme=gpgme
BUILDLINK_PREFIX.gpgme_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gpgme+=	include/gpgme.h
BUILDLINK_FILES.gpgme+=	lib/libgpgme-pthread.*
BUILDLINK_FILES.gpgme+=	lib/libgpgme.*

.include "../../security/libgpg-error/buildlink2.mk"

BUILDLINK_TARGETS+=	gpgme-buildlink

gpgme-buildlink: _BUILDLINK_USE

.endif	# GPGME_BUILDLINK2_MK
