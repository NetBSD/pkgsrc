# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 09:12:10 jlam Exp $

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
.endif	# GNOME_OBJC_BUILDLINK3_MK

.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
