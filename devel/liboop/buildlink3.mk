# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:21 joerg Exp $

BUILDLINK_TREE+=	liboop

.if !defined(LIBOOP_BUILDLINK3_MK)
LIBOOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboop+=	liboop>=0.9
BUILDLINK_ABI_DEPENDS.liboop+=	liboop>=1.0nb1
BUILDLINK_PKGSRCDIR.liboop?=	../../devel/liboop
.endif # LIBOOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboop
