# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:31:53 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CDPLAYER_BUILDLINK3_MK:=	${CDPLAYER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cdplayer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncdplayer}
BUILDLINK_PACKAGES+=	cdplayer

.if !empty(CDPLAYER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.cdplayer+=	cdplayer>=0.4.2
BUILDLINK_RECOMMENDED.cdplayer?=	cdplayer>=0.4.2nb2
BUILDLINK_PKGSRCDIR.cdplayer?=	../../audio/cdplayer
.endif	# CDPLAYER_BUILDLINK3_MK

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../audio/cddb-bundle/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
