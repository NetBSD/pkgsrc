# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:36:17 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libmikmod.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBMIKMOD_BUILDLINK3_MK:=	${LIBMIKMOD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmikmod
.endif

.if !empty(LIBMIKMOD_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libmikmod
BUILDLINK_DEPENDS.libmikmod+=		libmikmod>=3.1.9
BUILDLINK_PKGSRCDIR.libmikmod?=		../../audio/libmikmod

.include "../../audio/esound/buildlink3.mk"

.endif # LIBMIKMOD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
