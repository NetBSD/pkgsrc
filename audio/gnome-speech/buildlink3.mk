# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:07 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_SPEECH_BUILDLINK3_MK:=	${GNOME_SPEECH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-speech
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-speech}
BUILDLINK_PACKAGES+=	gnome-speech

.if !empty(GNOME_SPEECH_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-speech+=	gnome-speech>=0.2.7
BUILDLINK_PKGSRCDIR.gnome-speech?=	../../audio/gnome-speech

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"

.endif	# GNOME_SPEECH_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
