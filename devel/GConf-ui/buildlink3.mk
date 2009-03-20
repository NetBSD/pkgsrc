# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:08 joerg Exp $

BUILDLINK_TREE+=	GConf-ui

.if !defined(GCONF_UI_BUILDLINK3_MK)
GCONF_UI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GConf-ui+=	GConf-ui>=2.8.0.1
BUILDLINK_ABI_DEPENDS.GConf-ui?=	GConf-ui>=2.14.0nb1
BUILDLINK_PKGSRCDIR.GConf-ui?=	../../devel/GConf-ui

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GCONF_UI_BUILDLINK3_MK

BUILDLINK_TREE+=	-GConf-ui
