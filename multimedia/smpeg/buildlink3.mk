# $NetBSD: buildlink3.mk,v 1.1 2004/06/26 09:16:10 grant Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SPMEG_BUILDLINK3_MK:=	${SPMEG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	smpeg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsmpeg}
BUILDLINK_PACKAGES+=	smpeg

.if !empty(SPMEG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.smpeg+=	smpeg>=0.4.4nb3
BUILDLINK_PKGSRCDIR.smpeg?=	../../devel/smpeg
.endif	# SMPEG_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
