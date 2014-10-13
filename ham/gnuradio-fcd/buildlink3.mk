# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:09 mef Exp $

BUILDLINK_TREE+=	gnuradio-fcd

.if !defined(GNURADIO_FCD_BUILDLINK3_MK)
GNURADIO_FCD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fcd+=	gnuradio-fcd>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-fcd+=	gnuradio-fcd>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-fcd?=	../../ham/gnuradio-fcd
.endif # GNURADIO_FCD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fcd
