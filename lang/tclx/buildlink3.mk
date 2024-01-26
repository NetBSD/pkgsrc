# $NetBSD: buildlink3.mk,v 1.1 2024/01/26 13:13:35 wiz Exp $

BUILDLINK_TREE+=	tclx

.if !defined(TCLX_BUILDLINK3_MK)
TCLX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tclx+=	tclx>=8.6.3
BUILDLINK_ABI_DEPENDS.tclx+=	tclx>=8.6.3
BUILDLINK_PKGSRCDIR.tclx?=	../../lang/tclx

.include "../../lang/tcl/buildlink3.mk"
.endif # TCLX_BUILDLINK3_MK

BUILDLINK_TREE+=	-tclx
