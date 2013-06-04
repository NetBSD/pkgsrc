# $NetBSD: buildlink3.mk,v 1.12 2013/06/04 22:15:56 tron Exp $

BUILDLINK_TREE+=	tcl-tclcl

.if !defined(TCL_TCLCL_BUILDLINK3_MK)
TCL_TCLCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-tclcl+=	tcl-tclcl>=1.15
BUILDLINK_ABI_DEPENDS.tcl-tclcl+=	tcl-tclcl>=1.19nb3
BUILDLINK_PKGSRCDIR.tcl-tclcl?=	../../devel/tcl-tclcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif # TCL_TCLCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-tclcl
