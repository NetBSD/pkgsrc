# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/14 17:51:04 wiz Exp $
#

.if !defined(GPGME_BUILDLINK2_MK)
GPGME_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gpgme
BUILDLINK_DEPENDS.gpgme?=	gpgme>=0.3.15nb1
BUILDLINK_PKGSRCDIR.gpgme?=	../../security/gpgme

EVAL_PREFIX+=		BUILDLINK_PREFIX.gpgme=gpgme
BUILDLINK_PREFIX.gpgme_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gpgme+=	include/gpgme.h
BUILDLINK_FILES.gpgme+=	lib/libgpgme.*

BUILDLINK_TARGETS+=	gpgme-buildlink

gpgme-buildlink: _BUILDLINK_USE

.endif	# GPGME_BUILDLINK2_MK
