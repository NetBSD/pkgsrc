# $NetBSD: buildlink3.mk,v 1.3 2020/08/30 21:05:13 tnn Exp $

BUILDLINK_TREE+=	gnuradio-trellis

.if !defined(GNURADIO_TRELLIS_BUILDLINK3_MK)
GNURADIO_TRELLIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-trellis?=		../../ham/gnuradio-trellis
.endif # GNURADIO_TRELLIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-trellis
