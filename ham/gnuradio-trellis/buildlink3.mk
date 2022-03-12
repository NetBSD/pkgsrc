# $NetBSD: buildlink3.mk,v 1.6 2022/03/12 23:04:46 tnn Exp $

BUILDLINK_TREE+=	gnuradio-trellis

.if !defined(GNURADIO_TRELLIS_BUILDLINK3_MK)
GNURADIO_TRELLIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-trellis?=		../../ham/gnuradio-trellis
.endif # GNURADIO_TRELLIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-trellis
