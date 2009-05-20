# $NetBSD: buildlink3.mk,v 1.34 2009/05/20 13:19:04 wiz Exp $

BUILDLINK_TREE+=	nautilus

.if !defined(NAUTILUS_BUILDLINK3_MK)
NAUTILUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nautilus+=	nautilus>=2.12.1nb1
BUILDLINK_ABI_DEPENDS.nautilus?=	nautilus>=2.20.0nb2
BUILDLINK_PKGSRCDIR.nautilus?=	../../sysutils/nautilus

PRINT_PLIST_AWK+=	/^@dirrm lib\/nautilus$$/ \
				{ print "@comment in nautilus: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/nautilus\/extensions-2.0$$/ \
				{ print "@comment in nautilus: " $$0; next; }

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # NAUTILUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nautilus
