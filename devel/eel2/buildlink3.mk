# $NetBSD: buildlink3.mk,v 1.8 2004/10/03 00:13:26 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EEL2_BUILDLINK3_MK:=	${EEL2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	eel2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neel2}
BUILDLINK_PACKAGES+=	eel2

.if !empty(EEL2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.eel2+=	eel2>=2.8.0
BUILDLINK_RECOMMENDED.eel2+=	eel2>=2.8.0nb1
BUILDLINK_PKGSRCDIR.eel2?=	../../devel/eel2
.endif	# EEL2_BUILDLINK3_MK

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
