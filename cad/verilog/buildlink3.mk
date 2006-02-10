# $NetBSD: buildlink3.mk,v 1.1 2006/02/10 16:53:36 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.10.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.verilog?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
VERILOG_BUILDLINK3_MK:=	${VERILOG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	verilog
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nverilog}
BUILDLINK_PACKAGES+=	verilog

.if !empty(VERILOG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.verilog+=	verilog>=0.8.1nb1
BUILDLINK_PKGSRCDIR.verilog?=	../../cad/verilog
.endif	# VERILOG_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../archivers/bzip2/buildlink3.mk"
#.include "../../devel/gperf/buildlink3.mk"
#.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
