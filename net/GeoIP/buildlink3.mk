# $NetBSD: buildlink3.mk,v 1.1 2004/02/17 03:34:07 minskim Exp $
#
# This Makefile fragment is included by packages that use GeoIP.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GEOIP_BUILDLINK3_MK:=	${GEOIP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GeoIP
.endif

.if !empty(GEOIP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			GeoIP
BUILDLINK_DEPENDS.GeoIP+=		GeoIP>=1.3.1
BUILDLINK_PKGSRCDIR.GeoIP?=		../../net/GeoIP

.endif # GEOIP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
