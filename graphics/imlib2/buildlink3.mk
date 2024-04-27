# $NetBSD: buildlink3.mk,v 1.40 2024/04/27 03:05:37 schmonz Exp $

BUILDLINK_TREE+=	imlib2

.if !defined(IMLIB2_BUILDLINK3_MK)
IMLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.imlib2+=	imlib2>=1.1.0nb2
BUILDLINK_ABI_DEPENDS.imlib2+=	imlib2>=1.9.1nb4
BUILDLINK_PKGSRCDIR.imlib2?=	../../graphics/imlib2

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

pkgbase := imlib2
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.imlib2:Mx11}
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif
.endif # IMLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-imlib2
