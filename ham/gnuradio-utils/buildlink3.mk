# $NetBSD: buildlink3.mk,v 1.5 2022/03/12 23:04:46 tnn Exp $

BUILDLINK_TREE+=	gnuradio-utils

.if !defined(GNURADIO_UTILS_BUILDLINK3_MK)
GNURADIO_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.10.1.1
BUILDLINK_PKGSRCDIR.gnuradio-utils?=	../../ham/gnuradio-utils
.endif # GNURADIO_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-utils
