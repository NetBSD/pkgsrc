# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:18 joerg Exp $

BUILDLINK_TREE+=	libgcroots

.if !defined(LIBGCROOTS_BUILDLINK3_MK)
LIBGCROOTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgcroots+=	libgcroots>=0.2.1
BUILDLINK_PKGSRCDIR.libgcroots?=	../../devel/libgcroots
.endif # LIBGCROOTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgcroots
