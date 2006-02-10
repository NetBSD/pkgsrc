# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/02/10 16:37:51 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.10.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gplcver?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GPLCVER_BUILDLINK3_MK:=	${GPLCVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gplcver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngplcver}
BUILDLINK_PACKAGES+=	gplcver

.if !empty(GPLCVER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gplcver+=	gplcver>=2.11a
BUILDLINK_PKGSRCDIR.gplcver?=	../../cad/gplcver
.endif	# GPLCVER_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
