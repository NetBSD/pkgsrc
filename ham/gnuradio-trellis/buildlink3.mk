# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:10 mef Exp $

BUILDLINK_TREE+=	gnuradio-trellis

.if !defined(GNURADIO_TRELLIS_BUILDLINK3_MK)
GNURADIO_TRELLIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-trellis?=	../../ham/gnuradio-trellis
.endif # GNURADIO_TRELLIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-trellis
