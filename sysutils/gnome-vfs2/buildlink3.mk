# $NetBSD: buildlink3.mk,v 1.25 2006/09/15 15:07:40 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_VFS2_BUILDLINK3_MK:=	${GNOME_VFS2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfs2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-vfs2}
BUILDLINK_PACKAGES+=	gnome-vfs2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-vfs2

.if !empty(GNOME_VFS2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-vfs2+=		gnome-vfs2>=2.8.0
BUILDLINK_ABI_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.12.2nb2
BUILDLINK_PKGSRCDIR.gnome-vfs2?=	../../sysutils/gnome-vfs2

PRINT_PLIST_AWK+=	/^@dirrm lib\/gnome-vfs-2.0\/modules/ \
				{ print "@comment in gnome-vfs2: " $$0; next; }
.endif	# GNOME_VFS2_BUILDLINK3_MK

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/fam/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
