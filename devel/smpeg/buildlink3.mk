# $NetBSD: buildlink3.mk,v 1.2 2004/01/04 23:34:05 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SPMEG_BUILDLINK3_MK:=	${SPMEG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	smpeg
.endif

.if !empty(SPMEG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		smpeg
BUILDLINK_DEPENDS.smpeg?=	smpeg>=0.4.4nb3
BUILDLINK_PKGSRCDIR.smpeg?=	../../devel/smpeg

.  include "../../devel/SDL/buildlink3.mk"
.  include "../../devel/gettext-lib/buildlink3.mk"
.endif	# SMPEG_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
