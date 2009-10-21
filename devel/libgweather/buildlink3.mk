# $NetBSD: buildlink3.mk,v 1.5 2009/10/21 15:53:23 drochner Exp $

BUILDLINK_TREE+=	libgweather

.if !defined(LIBGWEATHER_BUILDLINK3_MK)
LIBGWEATHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgweather+=	libgweather>=2.22.0
BUILDLINK_ABI_DEPENDS.libgweather?=	libgweather>=2.26.2.1nb1
BUILDLINK_PKGSRCDIR.libgweather?=	../../devel/libgweather

.include "../../net/libsoup24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBGWEATHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgweather
