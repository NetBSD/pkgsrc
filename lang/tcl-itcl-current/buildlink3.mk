# $NetBSD: buildlink3.mk,v 1.10 2012/08/21 23:49:23 marino Exp $

BUILDLINK_TREE+=	tcl-itcl-current

.if !defined(TCL_ITCL_CURRENT_BUILDLINK3_MK)
TCL_ITCL_CURRENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-itcl-current+=		tcl-itcl-current>=20040920
BUILDLINK_ABI_DEPENDS.tcl-itcl-current+=	tcl-itcl-current>=20040920nb5
BUILDLINK_PKGSRCDIR.tcl-itcl-current?=		../../lang/tcl-itcl-current

BUILDLINK_TRANSFORM+=	l:itcl:itcl33
BUILDLINK_TRANSFORM+=	l:itk:itk33

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif # TCL_ITCL_CURRENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-itcl-current
