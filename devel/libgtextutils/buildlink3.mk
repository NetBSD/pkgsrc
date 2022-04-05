# $NetBSD: buildlink3.mk,v 1.1 2022/04/05 18:41:20 bacon Exp $

BUILDLINK_TREE+=	libgtextutils

.if !defined(LIBGTEXTUTILS_BUILDLINK3_MK)
LIBGTEXTUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtextutils+=	libgtextutils>=0.7
BUILDLINK_PKGSRCDIR.libgtextutils?=	../../devel/libgtextutils
.endif	# LIBGTEXTUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtextutils
