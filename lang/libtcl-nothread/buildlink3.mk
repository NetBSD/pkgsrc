# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:55 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TCLNT_BUILDLINK3_MK:=	${TCLNT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tclnt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntclnt}
BUILDLINK_PACKAGES+=	tclnt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tclnt

.if !empty(TCLNT_BUILDLINK3_MK:M+)
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
BUILD_ENV+=		_TCL_NOTHREAD=yes

.endif	# TCLNT_BUILDLINK3_MK

_TCL_NOTHREAD=		yes
.include "../../lang/tcl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
