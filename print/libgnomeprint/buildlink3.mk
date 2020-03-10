# $NetBSD: buildlink3.mk,v 1.60 2020/03/10 22:08:58 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	libgnomeprint

.if !defined(LIBGNOMEPRINT_BUILDLINK3_MK)
LIBGNOMEPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomeprint+=	libgnomeprint>=2.8.0
BUILDLINK_ABI_DEPENDS.libgnomeprint+=	libgnomeprint>=2.18.8nb36
BUILDLINK_PKGSRCDIR.libgnomeprint?=	../../print/libgnomeprint

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"

pkgbase := libgnomeprint
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libgnomeprint:Mcups)
.  include "../../print/libgnomecups/buildlink3.mk"
.endif
.endif # LIBGNOMEPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomeprint
