# $NetBSD: buildlink3.mk,v 1.10 2026/05/15 09:58:53 adam Exp $

BUILDLINK_TREE+=	gnuradio-dtv

.if !defined(GNURADIO_DTV_BUILDLINK3_MK)
GNURADIO_DTV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-dtv+=	gnuradio-dtv>=3.10.1.1
BUILDLINK_ABI_DEPENDS.gnuradio-dtv?=	gnuradio-dtv>=3.10.12.0nb10
BUILDLINK_PKGSRCDIR.gnuradio-dtv?=	../../ham/gnuradio-dtv

.include "../../ham/gnuradio-fec/buildlink3.mk"
.endif # GNURADIO_DTV_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-dtv
