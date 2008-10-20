# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/10/20 09:28:51 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
AUDACIOUS_BUILDLINK3_MK:=	${AUDACIOUS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	audacious
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Naudacious}
BUILDLINK_PACKAGES+=	audacious
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}audacious

.if ${AUDACIOUS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.audacious+=	audacious>=1.5.0
BUILDLINK_PKGSRCDIR.audacious?=	../../audio/audacious
BUILDLINK_DEPMETHOD.audacious?=	build
.endif	# AUDACIOUS_BUILDLINK3_MK

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libmcs/buildlink3.mk"
.include "../../devel/mowgli/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
