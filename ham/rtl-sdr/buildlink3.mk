# $NetBSD: buildlink3.mk,v 1.2 2016/01/26 09:10:39 dbj Exp $

BUILDLINK_TREE+=	rtl-sdr

.if !defined(RTL_SDR_BUILDLINK3_MK)
RTL_SDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rtl-sdr+=	rtl-sdr>=0.5.3
BUILDLINK_PKGSRCDIR.rtl-sdr?=	../../ham/rtl-sdr

.endif # RTL_SDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-rtl-sdr
