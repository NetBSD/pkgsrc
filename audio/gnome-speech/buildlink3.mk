# $NetBSD: buildlink3.mk,v 1.2 2004/02/17 23:50:33 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnome-speech.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_SPEECH_BUILDLINK3_MK:=	${GNOME_SPEECH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-speech
.endif

.if !empty(GNOME_SPEECH_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-speech
BUILDLINK_DEPENDS.gnome-speech+=		gnome-speech>=0.2.7
BUILDLINK_PKGSRCDIR.gnome-speech?=		../../audio/gnome-speech

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"

.endif # GNOME_SPEECH_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
