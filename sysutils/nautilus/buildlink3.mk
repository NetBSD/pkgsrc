# $NetBSD: buildlink3.mk,v 1.28 2008/01/18 05:09:44 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NAUTILUS_BUILDLINK3_MK:=	${NAUTILUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	nautilus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnautilus}
BUILDLINK_PACKAGES+=	nautilus
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}nautilus

.if !empty(NAUTILUS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.nautilus+=	nautilus>=2.12.1nb1
BUILDLINK_ABI_DEPENDS.nautilus?=	nautilus>=2.20.0nb1
BUILDLINK_PKGSRCDIR.nautilus?=	../../sysutils/nautilus

PRINT_PLIST_AWK+=	/^@dirrm lib\/nautilus$$/ \
				{ print "@comment in nautilus: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/nautilus\/extensions-1.0$$/ \
				{ print "@comment in nautilus: " $$0; next; }
.endif	# NAUTILUS_BUILDLINK3_MK

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/eel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
