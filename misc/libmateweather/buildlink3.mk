# $NetBSD: buildlink3.mk,v 1.2 2016/08/03 10:22:17 adam Exp $
#

BUILDLINK_TREE+=	libmateweather

.if !defined(LIBMATEWEATHER_BUILDLINK3_MK)
LIBMATEWEATHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmateweather+=	libmateweather>=1.8.0
BUILDLINK_ABI_DEPENDS.libmateweather?=	libmateweather>=1.14.0nb1
BUILDLINK_PKGSRCDIR.libmateweather?=	../../misc/libmateweather

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# LIBMATEWEATHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmateweather
