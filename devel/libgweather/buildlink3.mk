# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:19 joerg Exp $

BUILDLINK_TREE+=	libgweather

.if !defined(LIBGWEATHER_BUILDLINK3_MK)
LIBGWEATHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.22.0
BUILDLINK_PKGSRCDIR.libgweather?=	../../devel/libgweather

.include "../../net/libsoup24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif # LIBGWEATHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgweather
