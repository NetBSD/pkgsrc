# $NetBSD: buildlink2.mk,v 1.1 2003/08/09 13:05:55 wiz Exp $
#
# This Makefile fragment is included by packages that use tcl-expect.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(TCL_EXPECT_BUILDLINK2_MK)
TCL_EXPECT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			tcl-expect
BUILDLINK_DEPENDS.tcl-expect?=		tcl-expect>=5.38.0
BUILDLINK_PKGSRCDIR.tcl-expect?=		../../lang/tcl-expect

EVAL_PREFIX+=	BUILDLINK_PREFIX.tcl-expect=tcl-expect
BUILDLINK_PREFIX.tcl-expect_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tcl-expect+=	include/expect.h
BUILDLINK_FILES.tcl-expect+=	include/expect_comm.h
BUILDLINK_FILES.tcl-expect+=	include/expect_tcl.h
BUILDLINK_FILES.tcl-expect+=	include/tcldbg.h
BUILDLINK_FILES.tcl-expect+=	lib/libexpect538.*
BUILDLINK_FILES.tcl-expect+=	lib/tcl/expect5.38/pkgIndex.tcl

BUILDLINK_TARGETS+=	tcl-expect-buildlink

tcl-expect-buildlink: _BUILDLINK_USE

.endif	# TCL_EXPECT_BUILDLINK2_MK
