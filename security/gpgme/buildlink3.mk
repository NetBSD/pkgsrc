# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 02:30:49 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gpgme.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GPGME_BUILDLINK3_MK:=	${GPGME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gpgme
.endif

.if !empty(GPGME_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gpgme
BUILDLINK_DEPENDS.gpgme+=		gpgme>=0.4.3
BUILDLINK_PKGSRCDIR.gpgme?=		../../security/gpgme

.include "../../security/libgpg-error/buildlink3.mk"

.endif # GPGME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
