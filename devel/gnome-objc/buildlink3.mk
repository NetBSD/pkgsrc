# $NetBSD: buildlink3.mk,v 1.1 2004/03/12 22:51:25 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_OBJC_BUILDLINK3_MK:=	${GNOME_OBJC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-objc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-objc}
BUILDLINK_PACKAGES+=	gnome-objc

.if !empty(GNOME_OBJC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-objc+=		gnome-objc>=1.0.40nb4
BUILDLINK_PKGSRCDIR.gnome-objc?=	../../devel/gnome-objc

.include "../../x11/gnome-libs/buildlink3.mk"

.endif	# GNOME_OBJC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
