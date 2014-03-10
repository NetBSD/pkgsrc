# $NetBSD: buildlink3.mk,v 1.1 2014/03/10 14:20:44 taca Exp $

BUILDLINK_TREE+=	tcl

.if !defined(TCL_BUILDLINK3_MK)
TCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl+=	tcl>=8.5.7
BUILDLINK_ABI_DEPENDS.tcl+=	tcl>=8.5.7
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl85

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

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # TCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl
