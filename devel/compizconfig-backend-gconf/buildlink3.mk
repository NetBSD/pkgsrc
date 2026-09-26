# $NetBSD: buildlink3.mk,v 1.35 2026/09/26 07:38:07 wiz Exp $

BUILDLINK_TREE+=	compizconfig-backend-gconf

.if !defined(COMPIZCONFIG_BACKEND_GCONF_BUILDLINK3_MK)
COMPIZCONFIG_BACKEND_GCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compizconfig-backend-gconf+=	compizconfig-backend-gconf>=0.8.8
BUILDLINK_ABI_DEPENDS.compizconfig-backend-gconf?=	compizconfig-backend-gconf>=0.8.8nb79
BUILDLINK_PKGSRCDIR.compizconfig-backend-gconf?=	../../devel/compizconfig-backend-gconf

.include "../../x11/startup-notification/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libcompizconfig/buildlink3.mk"
.endif	# COMPIZCONFIG_BACKEND_GCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-compizconfig-backend-gconf
