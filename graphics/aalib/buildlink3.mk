# $NetBSD: buildlink3.mk,v 1.11 2007/05/30 08:54:30 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AALIB_BUILDLINK3_MK:=	${AALIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	aalib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Naalib}
BUILDLINK_PACKAGES+=	aalib
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}aalib

.if !empty(AALIB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.aalib+=	aalib>=1.4.0.4
BUILDLINK_ABI_DEPENDS.aalib+=	aalib>=1.4.0.5nb2
BUILDLINK_PKGSRCDIR.aalib?=	../../graphics/aalib
.endif	# AALIB_BUILDLINK3_MK

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

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
