# $NetBSD: buildlink3.mk,v 1.6 2007/05/21 09:56:15 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TCL_BUILDLINK3_MK:=	${TCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl}
BUILDLINK_PACKAGES+=	tcl
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tcl

.if !empty(TCL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.tcl+=		tcl>=8.3.4<8.4
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl83

BUILDLINK_FILES.tcl=	bin/tclsh*
#
# Make "-ltcl" resolve into "-ltcl83", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl83

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh

.endif	# TCL_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
