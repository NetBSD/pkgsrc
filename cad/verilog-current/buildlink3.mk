# $NetBSD: buildlink3.mk,v 1.1 2004/04/11 05:36:23 snj Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
VERILOG_CURRENT_BUILDLINK3_MK:=	${VERILOG_CURRENT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	verilog-current
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nverilog-current}
BUILDLINK_PACKAGES+=	verilog-current

.if !empty(VERILOG_CURRENT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.verilog-current+=	verilog-current>=20021019
BUILDLINK_PKGSRCDIR.verilog-current?=	../../cad/verilog-current
.endif	# VERILOG_CURRENT_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
