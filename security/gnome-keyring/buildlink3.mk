# $NetBSD: buildlink3.mk,v 1.2 2004/09/21 16:47:28 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_KEYRING_BUILDLINK3_MK:=	${GNOME_KEYRING_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-keyring
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-keyring}
BUILDLINK_PACKAGES+=	gnome-keyring

.if !empty(GNOME_KEYRING_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-keyring+=	gnome-keyring>=0.4.0
BUILDLINK_PKGSRCDIR.gnome-keyring?=	../../security/gnome-keyring

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GNOME_KEYRING_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
