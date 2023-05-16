# $NetBSD: buildlink3.mk,v 1.5 2023/05/16 21:20:49 wiz Exp $

BUILDLINK_TREE+=	gr-osmosdr

.if !defined(GR_OSMOSDR_BUILDLINK3_MK)
GR_OSMOSDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gr-osmosdr+=	gr-osmosdr>=0.2.2
BUILDLINK_ABI_DEPENDS.gr-osmosdr+=	gr-osmosdr>=0.2.4nb3
BUILDLINK_PKGSRCDIR.gr-osmosdr?=	../../ham/gr-osmosdr

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.endif	# GR_OSMOSDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gr-osmosdr
