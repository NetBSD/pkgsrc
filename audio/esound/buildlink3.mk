# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ESOUND_BUILDLINK3_MK:=	${ESOUND_BUILDLINK3_MK}+

.if !empty(ESOUND_BUILDLINK3_MK:M\+)
BUILDLINK_DEPENDS.esound?=	esound>=0.2.18
BUILDLINK_PKGSRCDIR.esound?=	../../audio/esound
.endif	# ESOUND_BUILDLINK3_MK

.if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	esound
.endif

.if !empty(ESOUND_BUILDLINK3_MK:M\+)
BUILDLINK_PACKAGES+=	esound

.  include "../../audio/libaudiofile/buildlink3.mk"
.endif	# ESOUND_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
