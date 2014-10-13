# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:08 mef Exp $

BUILDLINK_TREE+=	gnuradio-dtv

.if !defined(GNURADIO_DTV_BUILDLINK3_MK)
GNURADIO_DTV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-dtv+=	gnuradio-dtv>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-dtv+=	gnuradio-dtv>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-dtv?=	../../ham/gnuradio-dtv
.endif # GNURADIO_DTV_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-dtv
