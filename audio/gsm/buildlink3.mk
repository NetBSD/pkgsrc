# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:37:35 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gsm.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GSM_BUILDLINK3_MK:=	${GSM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gsm
.endif

.if !empty(GSM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gsm
BUILDLINK_DEPENDS.gsm+=		gsm>=1.0.10
BUILDLINK_PKGSRCDIR.gsm?=	../../audio/gsm

.endif # GSM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
