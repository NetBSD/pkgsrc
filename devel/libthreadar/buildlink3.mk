# $NetBSD: buildlink3.mk,v 1.1 2022/10/03 13:47:20 nros Exp $

BUILDLINK_TREE+=	libthreadar

.if !defined(LIBTHREADAR_BUILDLINK3_MK)
LIBTHREADAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libthreadar+=	libthreadar>=1.4.0
BUILDLINK_PKGSRCDIR.libthreadar?=	../../devel/libthreadar
.endif	# LIBTHREADAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libthreadar
