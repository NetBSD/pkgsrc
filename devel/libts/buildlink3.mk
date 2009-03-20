# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:23 joerg Exp $

BUILDLINK_DEPMETHOD.libts?=	build

BUILDLINK_TREE+=	libts

.if !defined(LIBTS_BUILDLINK3_MK)
LIBTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libts+=	libts>=1.08
BUILDLINK_PKGSRCDIR.libts?=	../../devel/libts
.endif # LIBTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libts
