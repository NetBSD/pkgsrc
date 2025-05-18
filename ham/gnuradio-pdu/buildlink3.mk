# $NetBSD: buildlink3.mk,v 1.4 2025/05/18 19:31:20 gdt Exp $

BUILDLINK_TREE+=	gnuradio-pdu

.if !defined(GNURADIO_PDU_BUILDLINK3_MK)
GNURADIO_PDU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-pdu+=	gnuradio-pdu>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-pdu?=		gnuradio-pdu>=3.10.12.0nb3
BUILDLINK_PKGSRCDIR.gnuradio-pdu?=		../../ham/gnuradio-pdu

.include "../../ham/gnuradio-core/buildlink3.mk"
.endif # GNURADIO_PDU_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-pdu
