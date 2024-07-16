# $NetBSD: buildlink3.mk,v 1.8 2024/07/16 10:02:03 prlw1 Exp $

BUILDLINK_TREE+=	gr-osmosdr

.if !defined(GR_OSMOSDR_BUILDLINK3_MK)
GR_OSMOSDR_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	filesystem

BUILDLINK_API_DEPENDS.gr-osmosdr+=	gr-osmosdr>=0.2.2
BUILDLINK_ABI_DEPENDS.gr-osmosdr+=	gr-osmosdr>=0.2.6nb1
BUILDLINK_PKGSRCDIR.gr-osmosdr?=	../../ham/gr-osmosdr

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.endif	# GR_OSMOSDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gr-osmosdr
