# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:38 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
VERILOG_BUILDLINK3_MK:=	${VERILOG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	verilog
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nverilog}
BUILDLINK_PACKAGES+=	verilog
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}verilog

.if !empty(VERILOG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.verilog+=	verilog>=0.8.1nb1
BUILDLINK_PKGSRCDIR.verilog?=	../../cad/verilog
.endif	# VERILOG_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
