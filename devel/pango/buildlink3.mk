# $NetBSD: buildlink3.mk,v 1.27 2011/11/01 06:01:02 sbd Exp $

BUILDLINK_TREE+=	pango

.if !defined(PANGO_BUILDLINK3_MK)
PANGO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pango+=	pango>=1.6.0
BUILDLINK_ABI_DEPENDS.pango+=	pango>=1.28.4nb2
BUILDLINK_PKGSRCDIR.pango?=	../../devel/pango

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := pango
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.pango:Mx11)
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # PANGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-pango
