# $NetBSD: buildlink3.mk,v 1.3 2004/01/05 11:05:46 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TCL_BUILDLINK3_MK:=	${TCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl
.endif

.if !empty(TCL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		tcl
BUILDLINK_DEPENDS.tcl?=		tcl>=8.3.4
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl

BUILDLINK_FILES.tcl=	bin/tclsh*
#
# Make "-ltcl" resolve into "-ltcl83", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl83

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
.endif	# TCL_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
