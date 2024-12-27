# $NetBSD: buildlink3.mk,v 1.86 2024/12/27 08:19:34 wiz Exp $

BUILDLINK_TREE+=	libgweather

.if !defined(LIBGWEATHER_BUILDLINK3_MK)
LIBGWEATHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.22.0
BUILDLINK_ABI_DEPENDS.libgweather+=	libgweather>=40.0nb28
BUILDLINK_PKGSRCDIR.libgweather?=	../../devel/libgweather

.include "../../geography/geocode-glib/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBGWEATHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgweather
