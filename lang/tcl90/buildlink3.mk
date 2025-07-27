# $NetBSD: buildlink3.mk,v 1.1 2025/07/27 09:17:06 wiz Exp $

BUILDLINK_TREE+=	tcl90

.if !defined(TCL90_BUILDLINK3_MK)
TCL90_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tcl90+=	tcl90>=9.0.2
BUILDLINK_ABI_DEPENDS.tcl90+=	tcl90>=9.0.2
BUILDLINK_PKGSRCDIR.tcl90?=	../../lang/tcl90

BUILDLINK_PASSTHRU_DIRS+=		${PREFIX}/tcl/9.0
BUILDLINK_FILES.tcl90+=			tcl/9.0/bin/*
BUILDLINK_FNAME_TRANSFORM.tcl90+=	-e s,tcl/9.0/bin,bin,
BUILDLINK_FNAME_TRANSFORM.tcl90+=	-e s,tcl/9.0/lib/pkgconfig,lib/pkgconfig,

BUILDLINK_FILES.tcl90+=	bin/tclsh*
#
# Make "-ltcl" resolve into "-ltcl9.0", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl9.0

TCL90_SUBDIR=		tcl/9.0

_TOOLS_USE_PKGSRC.tclsh=	yes

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl90}/lib/tclConfig.sh
TCLSH=			${BUILDLINK_PREFIX.tcl90}/bin/tclsh
# Bundled library
ITCL_VERSION=		4.3.3
TDBC_VERSION=		1.1.11

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # TCL90_BUILDLINK3_MK

BUILDLINK_TREE+=	-tcl90
