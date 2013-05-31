# $NetBSD: buildlink3.mk,v 1.1 2013/05/31 01:10:55 rodent Exp $

BUILDLINK_TREE+=	libXfontcache

.if !defined(LIBXFONTCACHE_BUILDLINK3_MK)
LIBXFONTCACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXfontcache+=	libXfontcache>=1.0.5
BUILDLINK_PKGSRCDIR.libXfontcache?=	../../fonts/libXfontcache

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# LIBXFONTCACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXfontcache
