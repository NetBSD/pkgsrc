# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/02/22 01:05:18 rh Exp $
#
# This Makefile fragment is included by packages that use libsieve.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(LIBSIEVE_BUILDLINK2_MK)
LIBSIEVE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libsieve
BUILDLINK_DEPENDS.libsieve?=		libsieve>=2.1.12
BUILDLINK_PKGSRCDIR.libsieve?=		../../mail/libsieve

EVAL_PREFIX+=	BUILDLINK_PREFIX.libsieve=libsieve
BUILDLINK_PREFIX.libsieve_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsieve+=	include/sieve/*.h
BUILDLINK_FILES.libsieve+=	lib/libsieve.*

.include "../../mail/cyrus-imapd/buildlink2.mk"

BUILDLINK_TARGETS+=	libsieve-buildlink

libsieve-buildlink: _BUILDLINK_USE

.endif	# LIBSIEVE_BUILDLINK2_MK
