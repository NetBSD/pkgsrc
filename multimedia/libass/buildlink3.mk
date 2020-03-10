# $NetBSD: buildlink3.mk,v 1.14 2020/03/10 22:08:56 wiz Exp $

BUILDLINK_TREE+=	libass

.if !defined(LIBASS_BUILDLINK3_MK)
LIBASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libass+=	libass>=0.9.12
BUILDLINK_ABI_DEPENDS.libass+=	libass>=0.14.0nb4
BUILDLINK_PKGSRCDIR.libass?=	../../multimedia/libass

.include "../../converters/fribidi/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.endif # LIBASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libass
