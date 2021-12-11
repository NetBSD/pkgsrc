# $NetBSD: buildlink3.mk,v 1.4 2021/12/11 14:57:51 tnn Exp $

BUILDLINK_TREE+=	gnuradio-trellis

.if !defined(GNURADIO_TRELLIS_BUILDLINK3_MK)
GNURADIO_TRELLIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.9.4.0
BUILDLINK_ABI_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.9.4.0
BUILDLINK_PKGSRCDIR.gnuradio-trellis?=		../../ham/gnuradio-trellis
.endif # GNURADIO_TRELLIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-trellis
