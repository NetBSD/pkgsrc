# $NetBSD: buildlink3.mk,v 1.1 2025/02/24 11:54:17 jmcneill Exp $

BUILDLINK_TREE+=	gnuradio-network

.if !defined(GNURADIO_NETWORK_BUILDLINK3_MK)
GNURADIO_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-network+=	gnuradio-network>=3.10.9.2
BUILDLINK_PKGSRCDIR.gnuradio-network?=	../../ham/gnuradio-network
.endif	# GNURADIO_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-network
