# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/04/20 18:03:29 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.szip?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SZIP_BUILDLINK3_MK:=	${SZIP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	szip
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nszip}
BUILDLINK_PACKAGES+=	szip

.if !empty(SZIP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.szip+=	szip>=1.1
BUILDLINK_PKGSRCDIR.szip?=	../../archivers/szip
.endif	# SZIP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
