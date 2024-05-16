# $NetBSD: buildlink3.mk,v 1.13 2024/05/16 09:21:37 nia Exp $

BUILDLINK_TREE+=	lame

.if !defined(LAME_BUILDLINK3_MK)
LAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lame+=	lame>=3.93.1nb2
BUILDLINK_ABI_DEPENDS.lame+=	lame>=3.96.1nb4
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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"

.endif # LAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-lame
