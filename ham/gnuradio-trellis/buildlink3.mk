# $NetBSD: buildlink3.mk,v 1.5 2022/01/16 18:06:27 tnn Exp $

BUILDLINK_TREE+=	gnuradio-trellis

.if !defined(GNURADIO_TRELLIS_BUILDLINK3_MK)
GNURADIO_TRELLIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.10.0.0
BUILDLINK_PKGSRCDIR.gnuradio-trellis?=		../../ham/gnuradio-trellis
.endif # GNURADIO_TRELLIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-trellis
