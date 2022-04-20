# $NetBSD: buildlink3.mk,v 1.1 2022/04/20 17:14:20 nia Exp $

BUILDLINK_TREE+=	libvterm01

.if !defined(LIBVTERM01_BUILDLINK3_MK)
LIBVTERM01_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvterm01+=	libvterm01>=0.0.0
BUILDLINK_PKGSRCDIR.libvterm01?=	../../devel/libvterm01
BUILDLINK_INCDIRS.libvterm01?=		include/libvterm01
BUILDLINK_LIBDIRS.libvterm01?=		lib/libvterm01

.endif	# LIBVTERM01_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvterm01
