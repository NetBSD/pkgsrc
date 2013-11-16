# $NetBSD: buildlink3.mk,v 1.1.1.1 2013/11/16 21:01:26 asau Exp $

BUILDLINK_TREE+=	tcl-tclOO

.if !defined(TCL_TCLOO_BUILDLINK3_MK)
TCL_TCLOO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-tclOO+=	tcl-tclOO>=0.6
BUILDLINK_PKGSRCDIR.tcl-tclOO?=		../../devel/tcl-tclOO
.endif # TCL_TCLOO_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-tclOO
