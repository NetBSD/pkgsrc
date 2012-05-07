# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:43 dholland Exp $

BUILDLINK_TREE+=	tcl-itcl

.if !defined(TCL_ITCL_BUILDLINK3_MK)
TCL_ITCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-itcl+=	tcl-itcl>=3.2.1
BUILDLINK_ABI_DEPENDS.tcl-itcl+=	tcl-itcl>=3.2.1nb1
BUILDLINK_PKGSRCDIR.tcl-itcl?=	../../lang/tcl-itcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif # TCL_ITCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-itcl
