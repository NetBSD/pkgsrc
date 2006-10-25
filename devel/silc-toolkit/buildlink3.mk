# $NetBSD: buildlink3.mk,v 1.7 2006/10/25 01:40:36 dmcmahill Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SILC_TOOLKIT_BUILDLINK3_MK:=	${SILC_TOOLKIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	silc-toolkit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsilc-toolkit}
BUILDLINK_PACKAGES+=	silc-toolkit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}silc-toolkit

.if !empty(SILC_TOOLKIT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.silc-toolkit+=	silc-toolkit>=0.9.12
BUILDLINK_ABI_DEPENDS.silc-toolkit+=	silc-toolkit>=0.9.12nb1
BUILDLINK_PKGSRCDIR.silc-toolkit?=	../../devel/silc-toolkit
.endif	# SILC_TOOLKIT_BUILDLINK3_MK

.include "../../devel/libgetopt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
