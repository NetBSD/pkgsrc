# $NetBSD: buildlink3.mk,v 1.1 2004/02/14 04:43:48 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use libgdgeda.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGDGEDA_BUILDLINK3_MK:=	${LIBGDGEDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgdgeda
.endif

.if !empty(LIBGDGEDA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgdgeda
BUILDLINK_DEPENDS.libgdgeda+=		libgdgeda>=2.0.15
BUILDLINK_PKGSRCDIR.libgdgeda?=		../../graphics/libgdgeda

.include "../../graphics/png/buildlink3.mk"

.endif # LIBGDGEDA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
