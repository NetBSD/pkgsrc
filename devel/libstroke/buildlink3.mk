# $NetBSD: buildlink3.mk,v 1.1 2004/02/14 05:08:50 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use libstroke.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSTROKE_BUILDLINK3_MK:=	${LIBSTROKE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libstroke
.endif

.if !empty(LIBSTROKE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libstroke
BUILDLINK_DEPENDS.libstroke+=		libstroke>=0.3nb1
BUILDLINK_PKGSRCDIR.libstroke?=		../../devel/libstroke

.include "../../lang/tcl/buildlink3.mk"

.endif # LIBSTROKE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
