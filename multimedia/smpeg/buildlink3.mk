# $NetBSD: buildlink3.mk,v 1.11 2009/03/19 15:31:42 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SMPEG_BUILDLINK3_MK:=	${SMPEG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	smpeg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsmpeg}
BUILDLINK_PACKAGES+=	smpeg
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}smpeg

.if !empty(SMPEG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.smpeg+=	smpeg>=0.4.4nb3
BUILDLINK_ABI_DEPENDS.smpeg+=	smpeg>=0.4.4nb13
BUILDLINK_PKGSRCDIR.smpeg?=	../../multimedia/smpeg
.endif	# SMPEG_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
