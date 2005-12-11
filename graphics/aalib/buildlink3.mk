# $NetBSD: buildlink3.mk,v 1.4 2005/12/11 09:40:44 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AALIB_BUILDLINK3_MK:=	${AALIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	aalib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Naalib}
BUILDLINK_PACKAGES+=	aalib

.if !empty(AALIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.aalib+=	aalib>=1.4.0.4
BUILDLINK_RECOMMENDED.aalib+=	aalib>=1.4.0.4nb2
BUILDLINK_PKGSRCDIR.aalib?=	../../graphics/aalib
.endif	# AALIB_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.aalib)
PKG_BUILD_OPTIONS.aalib!=						\
	cd ${BUILDLINK_PKGSRCDIR.aalib} &&				\
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.aalib=${PKG_BUILD_OPTIONS.aalib:Q}
.endif
MAKEVARS+=	PKG_BUILD_OPTIONS.aalib

.if !empty(PKG_BUILD_OPTIONS.aalib:Mncurses)
.  include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.aalib:Mslang)
.  include "../../devel/libslang/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.aalib:Mx11)
.  include "../../mk/x11.buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
