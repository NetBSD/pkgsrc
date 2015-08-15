# $NetBSD: buildlink3.mk,v 1.7 2015/08/15 22:46:38 wiz Exp $

BUILDLINK_TREE+=	libcdr

.if !defined(LIBCDR_BUILDLINK3_MK)
LIBCDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdr+=	libcdr>=0.0.6
BUILDLINK_ABI_DEPENDS.libcdr+=	libcdr>=0.1.1nb3
BUILDLINK_PKGSRCDIR.libcdr?=	../../converters/libcdr

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBCDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdr
