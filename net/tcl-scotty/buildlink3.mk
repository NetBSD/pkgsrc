# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:12 joerg Exp $

BUILDLINK_TREE+=	tcl-scotty

.if !defined(TCL_SCOTTY_BUILDLINK3_MK)
TCL_SCOTTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl-scotty+=	tcl-scotty>=2.1.11
BUILDLINK_ABI_DEPENDS.tcl-scotty+=	tcl-scotty>=2.1.11nb4
BUILDLINK_PKGSRCDIR.tcl-scotty?=	../../net/tcl-scotty

.include "../../lang/tcl/buildlink3.mk"
.endif # TCL_SCOTTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl-scotty
