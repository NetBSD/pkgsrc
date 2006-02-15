# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/02/15 16:58:21 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.10.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.ucl?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
UCL_BUILDLINK3_MK:=	${UCL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ucl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nucl}
BUILDLINK_PACKAGES+=	ucl

.if !empty(UCL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ucl+=	ucl>=1.03
BUILDLINK_PKGSRCDIR.ucl?=	../../archivers/ucl
.endif	# UCL_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
