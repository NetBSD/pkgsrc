# $NetBSD: buildlink3.mk,v 1.4 2009/08/26 19:56:56 sno Exp $

BUILDLINK_TREE+=	devhelp

.if !defined(DEVHELP_BUILDLINK3_MK)
DEVHELP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.devhelp+=	devhelp>=0.12nb1
BUILDLINK_ABI_DEPENDS.devhelp?=	devhelp>=0.23nb3
BUILDLINK_PKGSRCDIR.devhelp?=	../../devel/devhelp

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # DEVHELP_BUILDLINK3_MK

BUILDLINK_TREE+=	-devhelp
