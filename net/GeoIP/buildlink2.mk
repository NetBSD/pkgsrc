# $NetBSD: buildlink2.mk,v 1.2 2003/12/28 12:31:42 jmmv Exp $
#
# This Makefile fragment is included by packages that use GeoIP.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GEOIP_BUILDLINK2_MK)
GEOIP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			GeoIP
BUILDLINK_DEPENDS.GeoIP?=		GeoIP>=1.3.1
BUILDLINK_PKGSRCDIR.GeoIP?=		../../net/GeoIP

EVAL_PREFIX+=	BUILDLINK_PREFIX.GeoIP=GeoIP
BUILDLINK_PREFIX.GeoIP_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.GeoIP+=	include/GeoIP.h
BUILDLINK_FILES.GeoIP+=	include/GeoIPBitReader.h
BUILDLINK_FILES.GeoIP+=	include/GeoIPCity.h
BUILDLINK_FILES.GeoIP+=	include/GeoIPUpdate.h
BUILDLINK_FILES.GeoIP+=	lib/libGeoIP.*
BUILDLINK_FILES.GeoIP+=	lib/libGeoIPBitReader.*
BUILDLINK_FILES.GeoIP+=	lib/libGeoIPUpdate.*

BUILDLINK_TARGETS+=	GeoIP-buildlink

GeoIP-buildlink: _BUILDLINK_USE

.endif	# GEOIP_BUILDLINK2_MK
