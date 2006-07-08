# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 22:39:36 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_KEYRING_BUILDLINK3_MK:=	${GNOME_KEYRING_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-keyring
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-keyring}
BUILDLINK_PACKAGES+=	gnome-keyring
BUILDLINK_ORDER+=	gnome-keyring

.if !empty(GNOME_KEYRING_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-keyring+=	gnome-keyring>=0.4.0
BUILDLINK_ABI_DEPENDS.gnome-keyring+=	gnome-keyring>=0.4.9nb1
BUILDLINK_PKGSRCDIR.gnome-keyring?=	../../security/gnome-keyring

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GNOME_KEYRING_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
