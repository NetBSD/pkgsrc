# $NetBSD: buildlink3.mk,v 1.1 2004/04/25 00:18:39 wiz Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.hesiod?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HESIOD_BUILDLINK3_MK:=	${HESIOD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	hesiod
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhesiod}
BUILDLINK_PACKAGES+=	hesiod

.if !empty(HESIOD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.hesiod+=	hesiod>=3.0.2
BUILDLINK_PKGSRCDIR.hesiod?=	../../net/hesiod
.endif	# HESIOD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
