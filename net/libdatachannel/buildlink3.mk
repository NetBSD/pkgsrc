# $NetBSD: buildlink3.mk,v 1.1 2026/10/05 13:18:20 ktnb Exp $

BUILDLINK_TREE+=	libdatachannel

.if !defined(LIBDATACHANNEL_BUILDLINK3_MK)
LIBDATACHANNEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdatachannel+=	libdatachannel>=0.24.6
BUILDLINK_PKGSRCDIR.libdatachannel?=	../../net/libdatachannel

BUILDLINK_DEPMETHOD.libdatachannel?=	build
.endif	# LIBDATACHANNEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdatachannel
