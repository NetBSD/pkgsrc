# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:43 dholland Exp $

BUILDLINK_TREE+=	tcl-tclX

.if !defined(TCL_TCLX_BUILDLINK3_MK)
TCL_TCLX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-tclX+=	tcl-tclX>=8.3.5
BUILDLINK_ABI_DEPENDS.tcl-tclX+=	tcl-tclX>=8.3.5nb3
BUILDLINK_PKGSRCDIR.tcl-tclX?=	../../lang/tcl-tclX

.include "../../lang/tcl/buildlink3.mk"
.endif # TCL_TCLX_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-tclX
