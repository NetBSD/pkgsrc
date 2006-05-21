# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/05/21 22:21:10 ben Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PORTAUDIO_DEVEL_BUILDLINK3_MK:=	${PORTAUDIO_DEVEL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	portaudio-devel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nportaudio-devel}
BUILDLINK_PACKAGES+=	portaudio-devel

.if ${PORTAUDIO_DEVEL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.portaudio-devel+=	portaudio-devel>=20060521
BUILDLINK_PKGSRCDIR.portaudio-devel?=	../../audio/portaudio-devel
BUILDLINK_INCDIRS.portaudio-devel?=	include/portaudio2
BUILDLINK_LIBDIRS.portaudio-devel?=	lib/portaudio2
BUILDLINK_CPPFLAGS.portaudio-devel?=	-I${BUILDLINK_PREFIX.portaudio-devel}/include/portaudio2
.endif	# PORTAUDIO_DEVEL_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
