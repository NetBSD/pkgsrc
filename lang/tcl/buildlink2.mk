# $NetBSD: buildlink2.mk,v 1.7 2004/03/24 15:24:36 jwise Exp $

.if !defined(TCL_BUILDLINK2_MK)
TCL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tcl
BUILDLINK_DEPENDS.tcl?=		tcl>=8.4.6nb1
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl

EVAL_PREFIX+=		BUILDLINK_PREFIX.tcl=tcl
BUILDLINK_PREFIX.tcl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tcl=	bin/tclsh*
BUILDLINK_FILES.tcl+=	include/tcl.h
BUILDLINK_FILES.tcl+=	include/tclDecls.h
BUILDLINK_FILES.tcl+=	include/tclPlatDecls.h
BUILDLINK_FILES.tcl+=	include/tcl/*/*.h
BUILDLINK_FILES.tcl+=	lib/libtcl84.*
BUILDLINK_FILES.tcl+=	lib/libtclstub84.*

# Make "-ltcl" resolve into "-ltcl84", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl84

BUILDLINK_TARGETS+=	tcl-buildlink

tcl-buildlink: _BUILDLINK_USE

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh

.include "../../mk/pthread.buildlink2.mk"

.endif	# TCL_BUILDLINK2_MK
