# $NetBSD: buildlink3.mk,v 1.2 2025/02/27 13:53:33 adam Exp $

BUILDLINK_TREE+=	gnuradio-network

.if !defined(GNURADIO_NETWORK_BUILDLINK3_MK)
GNURADIO_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-network+=	gnuradio-network>=3.10.9.2
BUILDLINK_PKGSRCDIR.gnuradio-network?=		../../ham/gnuradio-network

.include "../../ham/gnuradio-core/buildlink3.mk"
.endif	# GNURADIO_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-network
