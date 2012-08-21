# $NetBSD: buildlink3.mk,v 1.9 2012/08/21 23:49:23 marino Exp $

BUILDLINK_TREE+=	tcl-tclX

.if !defined(TCL_TCLX_BUILDLINK3_MK)
TCL_TCLX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-tclX+=	tcl-tclX>=8.3.5
BUILDLINK_ABI_DEPENDS.tcl-tclX+=	tcl-tclX>=8.3.5nb4
BUILDLINK_PKGSRCDIR.tcl-tclX?=	../../lang/tcl-tclX

.include "../../lang/tcl/buildlink3.mk"
.endif # TCL_TCLX_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-tclX
