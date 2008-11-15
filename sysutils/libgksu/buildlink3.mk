# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/15 19:36:09 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGKSU_BUILDLINK3_MK:=	${LIBGKSU_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libgksu
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgksu}
BUILDLINK_PACKAGES+=	libgksu
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgksu

.if ${LIBGKSU_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libgksu+=	libgksu>=2.0.7
BUILDLINK_PKGSRCDIR.libgksu?=	../../zzz/libgksu
.endif	# LIBGKSU_BUILDLINK3_MK

.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
