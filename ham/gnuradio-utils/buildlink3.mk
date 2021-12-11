# $NetBSD: buildlink3.mk,v 1.3 2021/12/11 14:57:51 tnn Exp $

BUILDLINK_TREE+=	gnuradio-utils

.if !defined(GNURADIO_UTILS_BUILDLINK3_MK)
GNURADIO_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.9.4.0
BUILDLINK_ABI_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.9.4.0
BUILDLINK_PKGSRCDIR.gnuradio-utils?=	../../ham/gnuradio-utils
.endif # GNURADIO_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-utils
