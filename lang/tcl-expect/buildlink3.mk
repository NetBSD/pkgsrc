# $NetBSD: buildlink3.mk,v 1.1 2004/03/11 20:19:38 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_EXPECT_BUILDLINK3_MK:=	${TCL_EXPECT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-expect
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-expect}
BUILDLINK_PACKAGES+=	tcl-expect

.if !empty(TCL_EXPECT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl-expect+=	tcl-expect>=5.38.0nb1
BUILDLINK_PKGSRCDIR.tcl-expect?=	../../lang/tcl-expect

.include "../../lang/tcl/buildlink3.mk"

.endif	# TCL_EXPECT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
