# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:36 joerg Exp $

BUILDLINK_TREE+=	aalib

.if !defined(AALIB_BUILDLINK3_MK)
AALIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aalib+=	aalib>=1.4.0.4
BUILDLINK_ABI_DEPENDS.aalib+=	aalib>=1.4.0.5nb2
BUILDLINK_PKGSRCDIR.aalib?=	../../graphics/aalib

pkgbase := aalib
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.aalib:Mncurses)
.  include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.aalib:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.aalib:Mx11)
.  include "../../x11/libX11/buildlink3.mk"
.endif
.endif # AALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-aalib
