# $NetBSD: buildlink3.mk,v 1.4 2009/08/26 19:56:57 sno Exp $

BUILDLINK_TREE+=	libgweather

.if !defined(LIBGWEATHER_BUILDLINK3_MK)
LIBGWEATHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.22.0
BUILDLINK_ABI_DEPENDS.libgweather?=	libgweather>=2.26.2.1nb1
BUILDLINK_PKGSRCDIR.libgweather?=	../../devel/libgweather

.include "../../net/libsoup24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif # LIBGWEATHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgweather
