# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/07/04 13:51:08 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.glibmm24?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GLIBMM24_BUILDLINK3_MK:=	${GLIBMM24_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glibmm24
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglibmm24}
BUILDLINK_PACKAGES+=	glibmm24

.if !empty(GLIBMM24_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.glibmm24+=	glibmm24>=2.4.3
BUILDLINK_PKGSRCDIR.glibmm24?=	../../devel/glibmm24
.endif	# GLIBMM24_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
