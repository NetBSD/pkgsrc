# $NetBSD: buildlink3.mk,v 1.1 2014/11/14 08:03:31 markd Exp $

BUILDLINK_TREE+=	libkomparediff2

.if !defined(LIBKOMPAREDIFF2_BUILDLINK3_MK)
LIBKOMPAREDIFF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkomparediff2+=	libkomparediff2>=4.14.3
BUILDLINK_PKGSRCDIR.libkomparediff2?=	../../devel/libkomparediff2

.endif	# LIBKOMPAREDIFF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkomparediff2
