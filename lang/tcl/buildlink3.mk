# $NetBSD: buildlink3.mk,v 1.21 2009/06/14 22:58:03 joerg Exp $

BUILDLINK_TREE+=	tcl

.if !defined(TCL_BUILDLINK3_MK)
TCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl+=	tcl>=8.4.6nb1
BUILDLINK_ABI_DEPENDS.tcl+=	tcl>=8.4.7nb1
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl

BUILDLINK_FILES.tcl+=	bin/tclsh*
#
# Make "-ltcl" and "-ltcl8.4" resolve into "-ltcl84", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl84
BUILDLINK_TRANSFORM+=	l:tcl8.4:tcl84

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh

.include "../../mk/dlopen.buildlink3.mk"
.endif # TCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl
