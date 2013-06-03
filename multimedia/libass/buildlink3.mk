# $NetBSD: buildlink3.mk,v 1.5 2013/06/03 10:05:42 wiz Exp $

BUILDLINK_TREE+=	libass

.if !defined(LIBASS_BUILDLINK3_MK)
LIBASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libass+=	libass>=0.9.12
BUILDLINK_ABI_DEPENDS.libass+=	libass>=0.10.1nb1
BUILDLINK_PKGSRCDIR.libass?=	../../multimedia/libass

.include "../../converters/fribidi/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.endif # LIBASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libass
