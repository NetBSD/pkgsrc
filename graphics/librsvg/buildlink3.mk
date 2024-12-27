# $NetBSD: buildlink3.mk,v 1.85 2024/12/27 11:47:58 ryoon Exp $

BUILDLINK_TREE+=	librsvg

.if !defined(LIBRSVG_BUILDLINK3_MK)
LIBRSVG_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

.include "../../graphics/librsvg/available.mk"

.if ${LIBRSVG_TYPE} == "rust"
BUILDLINK_ABI_DEPENDS.librsvg+=	librsvg>=2.58.1nb4
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.41
BUILDLINK_PKGSRCDIR.librsvg?=	../../graphics/librsvg
.elif ${LIBRSVG_TYPE} == "c"
BUILDLINK_ABI_DEPENDS.librsvg+=	librsvg>=2.40.20nb4<2.41
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.12.6nb1<2.41
BUILDLINK_PKGSRCDIR.librsvg?=	../../graphics/librsvg-c

.include "../../textproc/libcroco/buildlink3.mk"
.else
PKG_FAIL_REASON+=	"[graphics/librsvg/buildlink3.mk] Invalid value ${LIBRSVG_TYPE} for LIBRSVG_TYPE."
.endif

.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBRSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsvg
