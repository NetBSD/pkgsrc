# $NetBSD: buildlink3.mk,v 1.24 2012/08/21 21:31:47 marino Exp $

BUILDLINK_TREE+=	tcl

.if !defined(TCL_BUILDLINK3_MK)
TCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl+=	tcl>=8.5.7
BUILDLINK_ABI_DEPENDS.tcl+=	tcl>=8.5.7
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl

BUILDLINK_FILES.tcl+=	bin/tclsh*
#
# Make "-ltcl" and "-ltcl8.5" resolve into "-ltcl85", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl85
BUILDLINK_TRANSFORM+=	l:tcl8.5:tcl85

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh

_TOOLS_USE_PKGSRC.tclsh=	yes

FIND_PREFIX:=		TOOLS_PREFIX.tclsh=tcl
.include "../../mk/find-prefix.mk"
TCLSH=			${TOOLS_PREFIX.tclsh}/bin/tclsh

.include "../../mk/dlopen.buildlink3.mk"
.endif # TCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl
