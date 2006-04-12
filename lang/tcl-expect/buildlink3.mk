# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:22 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TCL_EXPECT_BUILDLINK3_MK:=	${TCL_EXPECT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl-expect
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl-expect}
BUILDLINK_PACKAGES+=	tcl-expect

.if !empty(TCL_EXPECT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tcl-expect+=	tcl-expect>=5.38.0nb1
BUILDLINK_ABI_DEPENDS.tcl-expect+=	tcl-expect>=5.38.0nb2
BUILDLINK_PKGSRCDIR.tcl-expect?=	../../lang/tcl-expect
.endif	# TCL_EXPECT_BUILDLINK3_MK

.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
