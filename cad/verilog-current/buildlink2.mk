# $NetBSD: buildlink2.mk,v 1.1 2002/11/10 01:57:48 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use verilog-current.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(VERILOG_CURRENT_BUILDLINK2_MK)
VERILOG_CURRENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			verilog-current
BUILDLINK_DEPENDS.verilog-current?=		verilog-current>=20021019
BUILDLINK_PKGSRCDIR.verilog-current?=		../../cad/verilog-current

EVAL_PREFIX+=	BUILDLINK_PREFIX.verilog-current=verilog-current
BUILDLINK_PREFIX.verilog-current_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.verilog-current+=	include/acc_user.h
BUILDLINK_FILES.verilog-current+=	include/ivl_target.h
BUILDLINK_FILES.verilog-current+=	include/veriuser.h
BUILDLINK_FILES.verilog-current+=	include/vpi_user.h
BUILDLINK_FILES.verilog-current+=	lib/ivl/fpga.tgt
BUILDLINK_FILES.verilog-current+=	lib/ivl/iverilog.conf
BUILDLINK_FILES.verilog-current+=	lib/ivl/ivl
BUILDLINK_FILES.verilog-current+=	lib/ivl/ivlpp
BUILDLINK_FILES.verilog-current+=	lib/ivl/null.tgt
BUILDLINK_FILES.verilog-current+=	lib/ivl/system.vpi
BUILDLINK_FILES.verilog-current+=	lib/ivl/vvp.tgt
BUILDLINK_FILES.verilog-current+=	lib/libveriuser.*
BUILDLINK_FILES.verilog-current+=	lib/libvpi.*


BUILDLINK_TARGETS+=	verilog-current-buildlink

verilog-current-buildlink: _BUILDLINK_USE

.endif	# VERILOG_CURRENT_BUILDLINK2_MK
