# $NetBSD: buildlink3.mk,v 1.19 2008/03/06 14:53:54 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_VFS_BUILDLINK3_MK:=	${GNOME_VFS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-vfs}
BUILDLINK_PACKAGES+=	gnome-vfs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-vfs

.if !empty(GNOME_VFS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.8.0
BUILDLINK_ABI_DEPENDS.gnome-vfs+=	gnome-vfs>=2.20.1nb1
BUILDLINK_PKGSRCDIR.gnome-vfs?=		../../sysutils/gnome-vfs

PRINT_PLIST_AWK+=	/^@dirrm lib\/gnome-vfs-2.0\/modules/ \
				{ print "@comment in gnome-vfs: " $$0; next; }
.endif	# GNOME_VFS_BUILDLINK3_MK

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
