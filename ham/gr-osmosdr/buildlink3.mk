# $NetBSD: buildlink3.mk,v 1.1 2016/07/25 00:10:43 gdt Exp $

BUILDLINK_TREE+=	gr-osmosdr

.if !defined(GR_OSMOSDR_BUILDLINK3_MK)
GR_OSMOSDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gr-osmosdr+=	gr-osmosdr>=0.1.4nb2
BUILDLINK_PKGSRCDIR.gr-osmosdr?=	../../ham/gr-osmosdr

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../ham/gnuradio-core/buildlink3.mk"
.endif	# GR_OSMOSDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gr-osmosdr
