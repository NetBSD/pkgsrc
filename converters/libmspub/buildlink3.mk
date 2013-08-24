# $NetBSD: buildlink3.mk,v 1.1 2013/08/24 16:06:56 jaapb Exp $

BUILDLINK_TREE+=	libmspub

.if !defined(LIBMSPUB_BUILDLINK3_MK)
LIBMSPUB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmspub+=	libmspub>=0.0.6
BUILDLINK_PKGSRCDIR.libmspub?=	../../converters/libmspub

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBMSPUB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmspub
