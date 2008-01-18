# $NetBSD: buildlink3.mk,v 1.18 2008/01/18 05:08:55 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEPRINT_BUILDLINK3_MK:=	${LIBGNOMEPRINT_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomeprint
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomeprint}
BUILDLINK_PACKAGES+=	libgnomeprint
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgnomeprint

.if !empty(LIBGNOMEPRINT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgnomeprint+=	libgnomeprint>=2.8.0
BUILDLINK_ABI_DEPENDS.libgnomeprint+=	libgnomeprint>=2.18.2nb2
BUILDLINK_PKGSRCDIR.libgnomeprint?=	../../print/libgnomeprint
.endif	# LIBGNOMEPRINT_BUILDLINK3_MK

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

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
