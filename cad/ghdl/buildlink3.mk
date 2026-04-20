# $NetBSD: buildlink3.mk,v 1.2 2026/04/20 08:21:29 wiz Exp $

BUILDLINK_TREE+=	ghdl

.if !defined(GHDL_BUILDLINK3_MK)
GHDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghdl+=	ghdl>=5.1.1
BUILDLINK_ABI_DEPENDS.ghdl?=	ghdl>=6.0.0
BUILDLINK_PKGSRCDIR.ghdl?=	../../cad/ghdl

.include "../../lang/gcc14-gnat/buildlink3.mk"
.endif	# GHDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghdl
