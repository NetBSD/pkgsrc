# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:24:20 joerg Exp $

BUILDLINK_TREE+=	libmowgli

.if !defined(LIBMOWGLI_BUILDLINK3_MK)
LIBMOWGLI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmowgli+=	libmowgli>=0.7.0
BUILDLINK_PKGSRCDIR.libmowgli?=		../../devel/libmowgli
.endif # LIBMOWGLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmowgli
