# $NetBSD: buildlink2.mk,v 1.1 2003/02/21 22:47:10 rh Exp $
#
# This Makefile fragment is included by packages that use cyrus-imapd.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(CYRUS_IMAPD_BUILDLINK2_MK)
CYRUS_IMAPD_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			cyrus-imapd
BUILDLINK_DEPENDS.cyrus-imapd?=		cyrus-imapd>=2.1.11
BUILDLINK_PKGSRCDIR.cyrus-imapd?=		../../mail/cyrus-imapd21

EVAL_PREFIX+=	BUILDLINK_PREFIX.cyrus-imapd=cyrus-imapd
BUILDLINK_PREFIX.cyrus-imapd_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cyrus-imapd+=	include/cyrus/*.h
BUILDLINK_FILES.cyrus-imapd+=	lib/libacap.*
BUILDLINK_FILES.cyrus-imapd+=	lib/libcyrus.*

.include "../../databases/db3/buildlink2.mk"
.include "../../security/cyrus-sasl2/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"

BUILDLINK_TARGETS+=	cyrus-imapd-buildlink

cyrus-imapd-buildlink: _BUILDLINK_USE

.endif	# CYRUS_IMAPD_BUILDLINK2_MK
