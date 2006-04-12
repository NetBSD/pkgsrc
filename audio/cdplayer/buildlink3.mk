# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:00 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CDPLAYER_BUILDLINK3_MK:=	${CDPLAYER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cdplayer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncdplayer}
BUILDLINK_PACKAGES+=	cdplayer

.if !empty(CDPLAYER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.cdplayer+=	cdplayer>=0.4.2
BUILDLINK_ABI_DEPENDS.cdplayer?=	cdplayer>=0.4.2nb3
BUILDLINK_PKGSRCDIR.cdplayer?=	../../audio/cdplayer
.endif	# CDPLAYER_BUILDLINK3_MK

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../audio/cddb-bundle/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
