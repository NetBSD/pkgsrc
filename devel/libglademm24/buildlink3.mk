# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/07/04 13:51:40 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libglademm24?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADEMM24_BUILDLINK3_MK:=	${LIBGLADEMM24_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglademm24
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglademm24}
BUILDLINK_PACKAGES+=	libglademm24

.if !empty(LIBGLADEMM24_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libglademm24+=	libglademm24>=2.4.1
BUILDLINK_PKGSRCDIR.libglademm24?=	../../devel/libglademm24
.endif	# LIBGLADEMM24_BUILDLINK3_MK

.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
