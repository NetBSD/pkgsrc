# $NetBSD: buildlink3.mk,v 1.49 2018/11/12 03:51:08 ryoon Exp $

BUILDLINK_TREE+=	rrdtool

.if !defined(RRDTOOL_BUILDLINK3_MK)
RRDTOOL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rrdtool+=	rrdtool>=1.3.9
BUILDLINK_ABI_DEPENDS.rrdtool+=	rrdtool>=1.7.0nb4
BUILDLINK_PKGSRCDIR.rrdtool?=	../../databases/rrdtool

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.endif	# RRDTOOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-rrdtool
