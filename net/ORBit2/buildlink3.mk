# $NetBSD: buildlink3.mk,v 1.2 2004/02/10 20:45:02 jlam Exp $
#
# This Makefile fragment is included by packages that use ORBit2.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ORBIT2_BUILDLINK3_MK:=	${ORBIT2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ORBit2
.endif

.if !empty(ORBIT2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			ORBit2
BUILDLINK_DEPENDS.ORBit2?=		ORBit2>=2.8.2
BUILDLINK_PKGSRCDIR.ORBit2?=		../../net/ORBit2

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"

.endif # ORBIT2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
