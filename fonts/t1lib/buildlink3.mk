# $NetBSD: buildlink3.mk,v 1.2 2004/03/03 11:28:11 adam Exp $
#
# This Makefile fragment is included by packages that use t1lib.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
T1LIB_BUILDLINK3_MK:=	${T1LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	t1lib
.endif

.if !empty(T1LIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			t1lib
BUILDLINK_DEPENDS.t1lib+=		t1lib>=5.0.1
BUILDLINK_PKGSRCDIR.t1lib?=		../../fonts/t1lib

.endif # T1LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
