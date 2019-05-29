# $NetBSD: buildlink3.mk,v 1.47 2019/05/29 12:38:23 wiz Exp $

BUILDLINK_TREE+=	librsvg

.if !defined(LIBRSVG_BUILDLINK3_MK)
LIBRSVG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.12.6nb1
BUILDLINK_ABI_DEPENDS.librsvg+=		librsvg>=2.40.20nb4

.include "../../mk/bsd.fast.prefs.mk"

# platforms where pkgsrc supports lang/rust
.if (${MACHINE_ARCH} == "aarch64" \
  || ${MACHINE_ARCH} == "armv7" \
  || ${MACHINE_ARCH} == "i386" \
  || ${MACHINE_ARCH} == "powerpc" \
  || ${MACHINE_ARCH} == "sparc64" \
  || ${MACHINE_ARCH} == "x86_64") \
  && \
 (${OPSYS} == "Darwin" \
 || ${OPSYS} == "FreeBSD" \
 || ${OPSYS} == "Linux" \
 || ${OPSYS} == "NetBSD" \
 || ${OPSYS} == "SunOS")
LIBRSVG_USE_RUST?=	yes
.endif

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
