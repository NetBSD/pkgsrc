# $NetBSD: buildlink3.mk,v 1.64 2020/11/05 09:06:51 ryoon Exp $

BUILDLINK_TREE+=	libgweather

.if !defined(LIBGWEATHER_BUILDLINK3_MK)
LIBGWEATHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.22.0
BUILDLINK_ABI_DEPENDS.libgweather+=	libgweather>=3.36.1nb1
BUILDLINK_PKGSRCDIR.libgweather?=	../../devel/libgweather

.include "../../geography/geocode-glib/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # LIBGWEATHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgweather
