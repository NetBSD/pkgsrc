# $NetBSD: buildlink2.mk,v 1.2 2004/04/24 22:41:20 wiz Exp $

.if !defined(TCL_BUILDLINK2_MK)
TCL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tcl
BUILDLINK_DEPENDS.tcl?=		tcl-8.3.4*
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl83

EVAL_PREFIX+=		BUILDLINK_PREFIX.tcl=tcl
BUILDLINK_PREFIX.tcl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tcl=	bin/tclsh*
BUILDLINK_FILES.tcl+=	include/tcl.h
BUILDLINK_FILES.tcl+=	include/tclDecls.h
BUILDLINK_FILES.tcl+=	include/tclPlatDecls.h
BUILDLINK_FILES.tcl+=	include/tcl/*/*.h
BUILDLINK_FILES.tcl+=	lib/libtcl83.*
BUILDLINK_FILES.tcl+=	lib/libtclstub83.*

# Make "-ltcl" resolve into "-ltcl83", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl83

BUILDLINK_TARGETS+=	tcl-buildlink

tcl-buildlink: _BUILDLINK_USE

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh

.endif	# TCL_BUILDLINK2_MK
