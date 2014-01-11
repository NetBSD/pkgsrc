# $NetBSD: buildlink3.mk,v 1.9 2014/01/11 14:42:00 adam Exp $

BUILDLINK_TREE+=	tcl-expect

.if !defined(TCL_EXPECT_BUILDLINK3_MK)
TCL_EXPECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-expect+=	tcl-expect>=5.38.0nb1
BUILDLINK_ABI_DEPENDS.tcl-expect+=	tcl-expect>=5.45.0nb3
BUILDLINK_PKGSRCDIR.tcl-expect?=	../../lang/tcl-expect

.include "../../lang/tcl/buildlink3.mk"
.endif # TCL_EXPECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-expect
