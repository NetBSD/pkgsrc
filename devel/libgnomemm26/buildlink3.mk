# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/07/04 13:52:18 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libgnomemm26?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEMM26_BUILDLINK3_MK:=	${LIBGNOMEMM26_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomemm26
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomemm26}
BUILDLINK_PACKAGES+=	libgnomemm26

.if !empty(LIBGNOMEMM26_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomemm26+=	libgnomemm26>=2.6.0
BUILDLINK_PKGSRCDIR.libgnomemm26?=	../../devel/libgnomemm26
.endif	# LIBGNOMEMM26_BUILDLINK3_MK

.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
