# $NetBSD: buildlink3.mk,v 1.1 2006/05/16 08:21:48 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.12.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.exiv2?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EXIV2_BUILDLINK3_MK:=	${EXIV2_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	exiv2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nexiv2}
BUILDLINK_PACKAGES+=	exiv2

.if ${EXIV2_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.exiv2+=	exiv2>=0.9.1
BUILDLINK_PKGSRCDIR.exiv2?=	../../graphics/exiv2
.endif	# EXIV2_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
