# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:16 dholland Exp $

BUILDLINK_TREE+=	verilog

.if !defined(VERILOG_BUILDLINK3_MK)
VERILOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.verilog+=	verilog>=0.8.1nb1
BUILDLINK_ABI_DEPENDS.verilog+=	verilog>=0.8.7nb1
BUILDLINK_PKGSRCDIR.verilog?=	../../cad/verilog

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif # VERILOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-verilog
