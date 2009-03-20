# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:50 joerg Exp $

BUILDLINK_TREE+=	tclnt

.if !defined(TCLNT_BUILDLINK3_MK)
TCLNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tclnt+=	libtcl-nothread>=8.4.6
BUILDLINK_ABI_DEPENDS.tclnt+=	libtcl-nothread>=8.4.6nb1
BUILDLINK_PKGSRCDIR.tclnt?=	../../lang/libtcl-nothread

BUILDLINK_FILES.tcl=	bin/tclsh*
#
# Make "-ltcl" and "-ltcl8.4" resolve into "-ltcl84", so that we don't
# need to patch so many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl84-nothread
BUILDLINK_TRANSFORM+=	l:tcl8.4:tcl84-nothread

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig-nothread.sh
PKGSRC_MAKE_ENV+=	_TCL_NOTHREAD=yes

_TCL_NOTHREAD=		yes
.include "../../lang/tcl/buildlink3.mk"
.endif # TCLNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tclnt
