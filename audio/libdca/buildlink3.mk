# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:23:54 joerg Exp $

BUILDLINK_TREE+=	libdca

.if !defined(LIBDCA_BUILDLINK3_MK)
LIBDCA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdca+=	libdca>=0.0.5
BUILDLINK_PKGSRCDIR.libdca?=	../../audio/libdca
.endif # LIBDCA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdca
