# $NetBSD: buildlink3.mk,v 1.1 2004/02/23 23:51:52 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use libgeda.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGEDA_BUILDLINK3_MK:=	${LIBGEDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgeda
.endif

.if !empty(LIBGEDA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgeda
BUILDLINK_DEPENDS.libgeda+=		libgeda-20030901{,nb[0-9]*}
BUILDLINK_PKGSRCDIR.libgeda?=		../../cad/libgeda

.include "../../devel/libstroke/buildlink3.mk"
.include "../../graphics/libgdgeda/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBGEDA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
