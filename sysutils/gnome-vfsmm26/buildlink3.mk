# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/07/04 13:54:29 drochner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gnome-vfsmm26?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_VFSMM26_BUILDLINK3_MK:=	${GNOME_VFSMM26_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfsmm26
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-vfsmm26}
BUILDLINK_PACKAGES+=	gnome-vfsmm26

.if !empty(GNOME_VFSMM26_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-vfsmm26+=	gnome-vfsmm26>=2.6.1
BUILDLINK_PKGSRCDIR.gnome-vfsmm26?=	../../sysutils/gnome-vfsmm26
.endif	# GNOME_VFSMM26_BUILDLINK3_MK

.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../devel/glibmm24/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
