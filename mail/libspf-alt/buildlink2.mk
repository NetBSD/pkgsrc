# $NetBSD: buildlink2.mk,v 1.3 2004/04/15 20:27:18 tron Exp $

.if !defined(LIBSPF_ALT_BUILDLINK2_MK)
LIBSPF_ALT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libspf_alt
BUILDLINK_DEPENDS.libspf_alt?=	libspf_alt>=0.4.0nb1
BUILDLINK_PKGSRCDIR.libspf_alt?=	../../mail/libspf-alt

EVAL_PREFIX+=	BUILDLINK_PREFIX.libspf_alt=libspf_alt
BUILDLINK_PREFIX.libspf_alt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libspf_alt+=	include/spf_alt/spf.h
BUILDLINK_FILES.libspf_alt+=	include/spf_alt/spf_lib_version.h
BUILDLINK_FILES.libspf_alt+=	include/spf_alt/spf_dns.h
BUILDLINK_FILES.libspf_alt+=	include/spf_alt/spf_dns_cache.h
BUILDLINK_FILES.libspf_alt+=	include/spf_alt/spf_dns_null.h
BUILDLINK_FILES.libspf_alt+=	include/spf_alt/spf_dns_resolv.h
BUILDLINK_FILES.libspf_alt+=	include/spf_alt/spf_dns_test.h
BUILDLINK_FILES.libspf_alt+=	include/spf_alt/spf_dns_zone.h
BUILDLINK_FILES.libspf_alt+=	lib/libspf_alt.*

.include "../../net/bind9/buildlink2.mk"

BUILDLINK_TARGETS+=	libspf_alt-buildlink

libspf_alt-buildlink: _BUILDLINK_USE

.endif	# LIBSPF_ALT_BUILDLINK2_MK
