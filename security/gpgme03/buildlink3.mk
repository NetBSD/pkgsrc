# $NetBSD: buildlink3.mk,v 1.1 2004/02/14 18:45:25 minskim Exp $
#
# This Makefile fragment is included by packages that use gpgme.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GPGME_BUILDLINK3_MK:=	${GPGME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gpgme
.endif

.if !empty(GPGME_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gpgme
BUILDLINK_DEPENDS.gpgme+=		gpgme-0.3.[0-9]*
BUILDLINK_PKGSRCDIR.gpgme?=		../../security/gpgme03

.endif # GPGME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
