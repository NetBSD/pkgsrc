# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:32:32 wiz Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.9.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.pslib?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PSLIB_BUILDLINK3_MK:=	${PSLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pslib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npslib}
BUILDLINK_PACKAGES+=	pslib

.if !empty(PSLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pslib+=	pslib>=0.2.6
BUILDLINK_RECOMMENDED.pslib?=	pslib>=0.2.6nb2
BUILDLINK_PKGSRCDIR.pslib?=	../../print/pslib
.endif	# PSLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
