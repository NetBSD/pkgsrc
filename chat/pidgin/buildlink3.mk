# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/28 12:12:33 gdt Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PIDGIN_BUILDLINK3_MK:=	${PIDGIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	pidgin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npidgin}
BUILDLINK_PACKAGES+=	pidgin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pidgin

.if ${PIDGIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.pidgin+=	pidgin>=2.0.1nb1
BUILDLINK_PKGSRCDIR.pidgin?=	../../wip/pidgin
.endif	# PIDGIN_BUILDLINK3_MK

.include "../../wip/libpurple/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libSM/buildlink3.mk"
#.include "../../x11/libXScrnSaver/buildlink3.mk"
#.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
