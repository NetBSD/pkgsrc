# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/12 02:41:18 minskim Exp $
#
# This Makefile fragment is included by packages that use libpathan.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBPATHAN_BUILDLINK3_MK:=	${LIBPATHAN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libpathan
.endif

.if !empty(LIBPATHAN_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libpathan
BUILDLINK_DEPENDS.libpathan+=		libpathan>=1.2.2
BUILDLINK_PKGSRCDIR.libpathan?=		../../wip/libpathan

.include "../../textproc/xerces-c/buildlink3.mk"

.endif # LIBPATHAN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
