# $NetBSD: buildlink3.mk,v 1.21 2011/10/07 19:04:46 drochner Exp $

BUILDLINK_TREE+=	libmatroska

.if !defined(LIBMATROSKA_BUILDLINK3_MK)
LIBMATROSKA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmatroska+=	libmatroska>=0.8.0
BUILDLINK_ABI_DEPENDS.libmatroska+=	libmatroska>=1.3.0
BUILDLINK_PKGSRCDIR.libmatroska?=	../../multimedia/libmatroska

.include "../../devel/libebml/buildlink3.mk"
.endif # LIBMATROSKA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmatroska
