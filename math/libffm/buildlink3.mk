# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:32:14 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libffm.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBFFM_BUILDLINK3_MK:=	${LIBFFM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libffm
.endif

.if !empty(LIBFFM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libffm
BUILDLINK_DEPENDS.libffm+=		libffm>=0.28
BUILDLINK_PKGSRCDIR.libffm?=		../../math/libffm

.endif # LIBFFM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
