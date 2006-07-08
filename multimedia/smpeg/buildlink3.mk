# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:11:02 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SPMEG_BUILDLINK3_MK:=	${SPMEG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	smpeg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsmpeg}
BUILDLINK_PACKAGES+=	smpeg
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}smpeg

.if !empty(SPMEG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.smpeg+=	smpeg>=0.4.4nb3
BUILDLINK_ABI_DEPENDS.smpeg+=	smpeg>=0.4.4nb13
BUILDLINK_PKGSRCDIR.smpeg?=	../../multimedia/smpeg
.endif	# SMPEG_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
