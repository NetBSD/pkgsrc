# $NetBSD: buildlink3.mk,v 1.3 2026/11/25 14:42:03 wiz Exp $

BUILDLINK_TREE+=	sdl12-compat

.if !defined(SDL12_COMPAT_BUILDLINK3_MK)
SDL12_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sdl12-compat+=	sdl12-compat>=1.2.52
BUILDLINK_PKGSRCDIR.sdl12-compat?=	../../devel/sdl12-compat
BUILDLINK_INCDIRS.sdl12-compat+=	include/SDL

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.  include "../../mk/mesa.buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.endif

.endif	# SDL12_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdl12-compat
