# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/04/20 17:52:48 ben Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.3.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PORTAUDIO_BUILDLINK3_MK:=	${PORTAUDIO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	portaudio
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nportaudio}
BUILDLINK_PACKAGES+=	portaudio

.if !empty(PORTAUDIO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.portaudio+=	portaudio>=18.1
BUILDLINK_PKGSRCDIR.portaudio?=	../../wip/portaudio
.endif	# PORTAUDIO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
