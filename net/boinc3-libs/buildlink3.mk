# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/07/19 20:11:04 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BOINC_LIBS_BUILDLINK3_MK:=	${BOINC_LIBS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	boinclibs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nboinclibs}
BUILDLINK_PACKAGES+=	boinclibs

.if !empty(BOINC_LIBS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.boinclibs+=	boinc3-libs>=3.19.20040714
BUILDLINK_PKGSRCDIR.boinclibs?=	../../net/boinc3-libs

# installs static libraries only
BUILDLINK_DEPMETHOD.boinclibs?=	build
.endif	# BOINC_LIBS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
