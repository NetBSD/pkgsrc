# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:53 joerg Exp $

BUILDLINK_TREE+=	tcl

.if !defined(TCL_BUILDLINK3_MK)
TCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl+=		tcl>=8.3.4<8.4
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl83

BUILDLINK_FILES.tcl=	bin/tclsh*
#
# Make "-ltcl" resolve into "-ltcl83", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl83

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
.endif # TCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl
