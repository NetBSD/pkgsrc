# $NetBSD: buildlink2.mk,v 1.1 2003/05/12 17:17:35 jmmv Exp $
#
# This Makefile fragment is included by packages that use bind.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(BIND_BUILDLINK2_MK)
BIND_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			bind
BUILDLINK_DEPENDS.bind?=		bind>=9.2.2
BUILDLINK_PKGSRCDIR.bind?=		../../net/bind9

EVAL_PREFIX+=	BUILDLINK_PREFIX.bind=bind
BUILDLINK_PREFIX.bind_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.bind+=	include/dns/*.h
BUILDLINK_FILES.bind+=	include/dst/*.h
BUILDLINK_FILES.bind+=	include/isc/*.h
BUILDLINK_FILES.bind+=	include/isccc/*.h
BUILDLINK_FILES.bind+=	include/isccfg/*.h
BUILDLINK_FILES.bind+=	include/lwres/*.h
BUILDLINK_FILES.bind+=	lib/libdns.*
BUILDLINK_FILES.bind+=	lib/libisc.*
BUILDLINK_FILES.bind+=	lib/libisccc.*
BUILDLINK_FILES.bind+=	lib/libisccfg.*
BUILDLINK_FILES.bind+=	lib/liblwres.*

.include "../../security/openssl/buildlink2.mk"

BUILDLINK_TARGETS+=	bind-buildlink

bind-buildlink: _BUILDLINK_USE

.endif	# BIND_BUILDLINK2_MK
