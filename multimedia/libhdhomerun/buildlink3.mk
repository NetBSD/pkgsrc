# $NetBSD: buildlink3.mk,v 1.1 2013/04/01 21:08:38 jmcneill Exp $

BUILDLINK_TREE+=	libhdhomerun

.if !defined(LIBHDHOMERUN_BUILDLINK3_MK)
LIBHDHOMERUN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhdhomerun+=	libhdhomerun>=20130328
BUILDLINK_PKGSRCDIR.libhdhomerun?=	../../multimedia/libhdhomerun
.endif	# LIBHDHOMERUN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhdhomerun
