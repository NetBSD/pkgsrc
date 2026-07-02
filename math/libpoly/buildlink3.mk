# $NetBSD: buildlink3.mk,v 1.1 2026/07/02 22:34:07 alnsn Exp $

BUILDLINK_TREE+=	libpoly

.if !defined(LIBPOLY_BUILDLINK3_MK)
LIBPOLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpoly+=	libpoly>=0.2.1
BUILDLINK_ABI_DEPENDS.libpoly+=	libpoly>=0.2.1
BUILDLINK_PKGSRCDIR.libpoly?=	../../math/libpoly
.endif # LIBPOLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpoly
