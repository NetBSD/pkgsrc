# $NetBSD: buildlink3.mk,v 1.7 2013/04/06 13:46:33 rodent Exp $

BUILDLINK_TREE+=	libts

.if !defined(LIBTS_BUILDLINK3_MK)
LIBTS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libts?=	build

BUILDLINK_API_DEPENDS.libts+=	libts>=1.08
BUILDLINK_PKGSRCDIR.libts?=	../../devel/libts
.endif # LIBTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libts
