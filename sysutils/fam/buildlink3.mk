# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 00:39:29 xtraeme Exp $
#
# This Makefile fragment is included by packages that use fam.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FAM_BUILDLINK3_MK:=	${FAM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fam
.endif

.if !empty(FAM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		fam
BUILDLINK_DEPENDS.fam+=		fam>=2.6.10
BUILDLINK_PKGSRCDIR.fam?=	../../sysutils/fam

.endif # FAM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
