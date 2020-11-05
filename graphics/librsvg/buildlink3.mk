# $NetBSD: buildlink3.mk,v 1.60 2020/11/05 09:06:55 ryoon Exp $

BUILDLINK_TREE+=	librsvg

.if !defined(LIBRSVG_BUILDLINK3_MK)
LIBRSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.12.6nb1

.include "../../mk/bsd.fast.prefs.mk"

.include "../../graphics/librsvg/available.mk"

.if ${LIBRSVG_TYPE} == "rust"
BUILDLINK_ABI_DEPENDS.librsvg?=	librsvg>=2.48.3nb3
BUILDLINK_PKGSRCDIR.librsvg?=	../../graphics/librsvg
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.41
BUILDLINK_ABI_DEPENDS.librsvg+=	librsvg>=2.48.0
.elif ${LIBRSVG_TYPE} == "c"
BUILDLINK_PKGSRCDIR.librsvg?=	../../graphics/librsvg-c
BUILDLINK_API_DEPENDS.librsvg+=	librsvg<2.41
BUILDLINK_ABI_DEPENDS.librsvg+=	librsvg>=2.40.20nb4

.include "../../textproc/libcroco/buildlink3.mk"
.else
PKG_FAIL_REASON+=		"[graphics/librsvg/buildlink3.mk] Invalid value ${LIBRSVG_TYPE} for LIBRSVG_TYPE."
.endif

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif # LIBRSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsvg
