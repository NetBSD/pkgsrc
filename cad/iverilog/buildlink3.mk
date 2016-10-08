# $NetBSD: buildlink3.mk,v 1.1 2016/10/08 23:01:45 kamil Exp $

BUILDLINK_TREE+=	iverilog

.if !defined(IVERILOG_BUILDLINK3_MK)
IVERILOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iverilog+=	iverilog>=10.1.1
BUILDLINK_PKGSRCDIR.iverilog?=	../../cad/iverilog

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.endif	# IVERILOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-iverilog
