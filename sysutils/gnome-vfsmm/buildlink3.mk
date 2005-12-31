# $NetBSD: buildlink3.mk,v 1.2 2005/12/31 12:32:45 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_VFSMM_BUILDLINK3_MK:=	${GNOME_VFSMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfsmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-vfsmm}
BUILDLINK_PACKAGES+=	gnome-vfsmm

.if !empty(GNOME_VFSMM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-vfsmm+=	gnome-vfsmm>=2.10.0
BUILDLINK_RECOMMENDED.gnome-vfsmm?=	gnome-vfsmm>=2.12.0nb1
BUILDLINK_PKGSRCDIR.gnome-vfsmm?=	../../sysutils/gnome-vfsmm
.endif	# GNOME_VFSMM_BUILDLINK3_MK

.include "../../devel/glibmm/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
