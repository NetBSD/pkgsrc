# $NetBSD: buildlink3.mk,v 1.15 2012/09/07 19:17:08 adam Exp $

BUILDLINK_TREE+=	goffice0.8

.if !defined(GOFFICE0.8_BUILDLINK3_MK)
GOFFICE0.8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.goffice0.8+=	goffice0.8>=0.8.0
BUILDLINK_ABI_DEPENDS.goffice0.8+=	goffice0.8>=0.8.17nb7
BUILDLINK_PKGSRCDIR.goffice0.8?=	../../misc/goffice0.8

#.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GOFFICE0.8_BUILDLINK3_MK

BUILDLINK_TREE+=	-goffice0.8
