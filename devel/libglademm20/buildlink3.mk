# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/07/06 20:41:07 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libglademm20?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGLADEMM20_BUILDLINK3_MK:=	${LIBGLADEMM20_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libglademm20
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibglademm20}
BUILDLINK_PACKAGES+=	libglademm20

.if !empty(LIBGLADEMM20_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libglademm20+=	libglademm20>=2.2.0
BUILDLINK_PKGSRCDIR.libglademm20?=	../../devel/libglademm20
.endif	# LIBGLADEMM20_BUILDLINK3_MK

.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
