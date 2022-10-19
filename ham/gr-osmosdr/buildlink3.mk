# $NetBSD: buildlink3.mk,v 1.4 2022/10/19 18:38:29 adam Exp $

BUILDLINK_TREE+=	gr-osmosdr

.if !defined(GR_OSMOSDR_BUILDLINK3_MK)
GR_OSMOSDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gr-osmosdr+=	gr-osmosdr>=0.2.2
BUILDLINK_ABI_DEPENDS.gr-osmosdr+=	gr-osmosdr>=0.2.3.20210128nb4
BUILDLINK_PKGSRCDIR.gr-osmosdr?=	../../ham/gr-osmosdr

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.endif	# GR_OSMOSDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gr-osmosdr
