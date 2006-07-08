# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:35 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CDPLAYER_BUILDLINK3_MK:=	${CDPLAYER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cdplayer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncdplayer}
BUILDLINK_PACKAGES+=	cdplayer
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}cdplayer

.if !empty(CDPLAYER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.cdplayer+=	cdplayer>=0.4.2
BUILDLINK_ABI_DEPENDS.cdplayer?=	cdplayer>=0.4.2nb3
BUILDLINK_PKGSRCDIR.cdplayer?=	../../audio/cdplayer
.endif	# CDPLAYER_BUILDLINK3_MK

.include "../../audio/libcdaudio/buildlink3.mk"
.include "../../audio/cddb-bundle/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
