# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:04 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RECODE_BUILDLINK3_MK:=	${RECODE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	recode
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrecode}
BUILDLINK_PACKAGES+=	recode

.if !empty(RECODE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.recode+=	recode>=3.6nb1
BUILDLINK_ABI_DEPENDS.recode+=	recode>=3.6nb3
BUILDLINK_PKGSRCDIR.recode?=	../../converters/recode
.endif	# RECODE_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
