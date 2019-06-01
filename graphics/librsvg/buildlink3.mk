# $NetBSD: buildlink3.mk,v 1.48 2019/06/01 13:55:31 wiz Exp $

BUILDLINK_TREE+=	librsvg

.if !defined(LIBRSVG_BUILDLINK3_MK)
LIBRSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.12.6nb1
BUILDLINK_ABI_DEPENDS.librsvg+=		librsvg>=2.40.20nb4

.include "../../mk/bsd.fast.prefs.mk"

# default to rust version on platforms where pkgsrc supports lang/rust
.include "../../lang/rust/platform.mk"
LIBRSVG_USE_RUST?=	${PLATFORM_SUPPORTS_RUST}

.if ${LIBRSVG_USE_RUST} == "yes"
BUILDLINK_PKGSRCDIR.librsvg?=		../../graphics/librsvg
BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.41
.else
BUILDLINK_PKGSRCDIR.librsvg?=		../../graphics/librsvg-c
BUILDLINK_API_DEPENDS.librsvg+=		librsvg<2.41
.endif

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.endif # LIBRSVG_BUILDLINK3_MK

BUILDLINK_TREE+=	-librsvg
