# $NetBSD: buildlink3.mk,v 1.7 2004/03/24 15:24:36 jwise Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TCL_BUILDLINK3_MK:=	${TCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tcl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntcl}
BUILDLINK_PACKAGES+=	tcl

.if !empty(TCL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.tcl+=		tcl>=8.4.6nb1
BUILDLINK_PKGSRCDIR.tcl?=	../../lang/tcl

BUILDLINK_FILES.tcl=	bin/tclsh*
#
# Make "-ltcl" resolve into "-ltcl84", so that we don't need to patch so
# many Makefiles.
#
BUILDLINK_TRANSFORM+=	l:tcl:tcl84

TCLCONFIG_SH?=		${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh

.endif	# TCL_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.include "../../mk/pthread.buildlink3.mk"
