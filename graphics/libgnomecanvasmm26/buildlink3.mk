# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:14:55 tv Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libgnomecanvasmm26?=	build

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
LIBGNOMECANVASMM26_BUILDLINK3_MK:=	${LIBGNOMECANVASMM26_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomecanvasmm26
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomecanvasmm26}
BUILDLINK_PACKAGES+=	libgnomecanvasmm26

.if !empty(LIBGNOMECANVASMM26_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomecanvasmm26+=	libgnomecanvasmm26>=2.6.1
BUILDLINK_RECOMMENDED.libgnomecanvasmm26+=	libgnomecanvasmm26>=2.6.1nb1
BUILDLINK_PKGSRCDIR.libgnomecanvasmm26?=	../../graphics/libgnomecanvasmm26
.endif	# LIBGNOMECANVASMM26_BUILDLINK3_MK

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtkmm24/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
