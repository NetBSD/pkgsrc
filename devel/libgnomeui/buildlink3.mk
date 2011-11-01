# $NetBSD: buildlink3.mk,v 1.37 2011/11/01 06:00:58 sbd Exp $

BUILDLINK_TREE+=	libgnomeui

.if !defined(LIBGNOMEUI_BUILDLINK3_MK)
LIBGNOMEUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomeui+=		libgnomeui>=2.8.0
BUILDLINK_ABI_DEPENDS.libgnomeui+=	libgnomeui>=2.24.5nb3
BUILDLINK_PKGSRCDIR.libgnomeui?=	../../devel/libgnomeui

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif # LIBGNOMEUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomeui
