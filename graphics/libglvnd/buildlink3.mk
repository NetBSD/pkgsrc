# $NetBSD: buildlink3.mk,v 1.1 2019/08/30 14:39:53 nia Exp $

BUILDLINK_TREE+=	libglvnd

.if !defined(LIBGLVND_BUILDLINK3_MK)
LIBGLVND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglvnd+=	libglvnd>=1.1.1
BUILDLINK_PKGSRCDIR.libglvnd?=	../../graphics/libglvnd
.endif	# LIBGLVND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglvnd
