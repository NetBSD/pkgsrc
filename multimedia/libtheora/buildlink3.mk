# $NetBSD: buildlink3.mk,v 1.3 2004/10/03 00:13:03 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTHEORA_BUILDLINK3_MK:=	${LIBTHEORA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtheora
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtheora}
BUILDLINK_PACKAGES+=	libtheora

.if !empty(LIBTHEORA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libtheora+=	libtheora>=1.0alpha3
BUILDLINK_RECOMMENDED.libtheora+=	libtheora>=1.0alpha3nb1
BUILDLINK_PKGSRCDIR.libtheora?=	../../multimedia/libtheora
.endif	# LIBTHEORA_BUILDLINK3_MK

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
