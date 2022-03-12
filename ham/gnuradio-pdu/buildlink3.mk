# $NetBSD: buildlink3.mk,v 1.2 2022/03/12 23:04:45 tnn Exp $

BUILDLINK_TREE+=	gnuradio-pdu

.if !defined(GNURADIO_PDU_BUILDLINK3_MK)
GNURADIO_PDU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-pdu+=	gnuradio-pdu>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-pdu?=		../../ham/gnuradio-pdu
.endif # GNURADIO_PDU_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-pdu
