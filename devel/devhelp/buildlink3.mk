# $NetBSD: buildlink3.mk,v 1.9 2010/11/15 22:56:36 abs Exp $

BUILDLINK_TREE+=	devhelp

.if !defined(DEVHELP_BUILDLINK3_MK)
DEVHELP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.devhelp+=	devhelp>=0.12nb1
BUILDLINK_ABI_DEPENDS.devhelp?=	devhelp>=2.30.1nb2
BUILDLINK_PKGSRCDIR.devhelp?=	../../devel/devhelp

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # DEVHELP_BUILDLINK3_MK

BUILDLINK_TREE+=	-devhelp
