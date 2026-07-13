# $NetBSD: buildlink3.mk,v 1.15 2026/07/13 04:35:12 wiz Exp $

BUILDLINK_TREE+=	lame

.if !defined(LAME_BUILDLINK3_MK)
LAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lame+=	lame>=3.93.1nb2
BUILDLINK_ABI_DEPENDS.lame+=	lame>=4.0
BUILDLINK_PKGSRCDIR.lame?=	../../audio/lame

pkgbase:= lame
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.lame:Municode}
.  include "../../converters/libiconv/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${MACHINE_ARCH} == "alpha"
.  include "../../math/libffm/buildlink3.mk"
.endif

.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"

.endif # LAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-lame
