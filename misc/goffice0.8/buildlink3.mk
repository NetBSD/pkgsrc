# $NetBSD: buildlink3.mk,v 1.35 2020/03/08 16:47:55 wiz Exp $

BUILDLINK_TREE+=	goffice0.8

.if !defined(GOFFICE0.8_BUILDLINK3_MK)
GOFFICE0.8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.goffice0.8+=	goffice0.8>=0.8.0
BUILDLINK_ABI_DEPENDS.goffice0.8+=	goffice0.8>=0.8.17nb27
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
