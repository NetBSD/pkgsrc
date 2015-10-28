# $NetBSD: buildlink3.mk,v 1.1 2015/10/28 19:00:58 wiz Exp $

BUILDLINK_TREE+=	libcerf

.if !defined(LIBCERF_BUILDLINK3_MK)
LIBCERF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcerf+=	libcerf>=1.4
BUILDLINK_PKGSRCDIR.libcerf?=	../../devel/libcerf
.endif	# LIBCERF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcerf
