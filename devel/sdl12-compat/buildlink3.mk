# $NetBSD: buildlink3.mk,v 1.1 2022/04/01 10:43:05 nia Exp $

BUILDLINK_TREE+=	sdl12-compat

.if !defined(SDL12_COMPAT_BUILDLINK3_MK)
SDL12_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sdl12-compat+=	sdl12-compat>=1.2.52
BUILDLINK_PKGSRCDIR.sdl12-compat?=	../../devel/sdl12-compat
BUILDLINK_INCDIRS.sdl12-compat+=	include/SDL

.endif	# SDL12_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdl12-compat
