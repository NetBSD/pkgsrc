# $NetBSD: buildlink3.mk,v 1.1 2025/12/25 16:39:59 ryoon Exp $

BUILDLINK_TREE+=	ghdl

.if !defined(GHDL_BUILDLINK3_MK)
GHDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghdl+=	ghdl>=5.1.1
BUILDLINK_PKGSRCDIR.ghdl?=	../../cad/ghdl

.include "../../lang/gcc14-gnat/buildlink3.mk"
.endif	# GHDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghdl
