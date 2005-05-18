# $NetBSD: buildlink3.mk,v 1.15 2005/05/18 18:50:19 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_VFS2_BUILDLINK3_MK:=	${GNOME_VFS2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfs2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-vfs2}
BUILDLINK_PACKAGES+=	gnome-vfs2

.if !empty(GNOME_VFS2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-vfs2+=		gnome-vfs2>=2.8.0
BUILDLINK_RECOMMENDED.gnome-vfs2+=	gnome-vfs2>=2.10.1
BUILDLINK_PKGSRCDIR.gnome-vfs2?=	../../sysutils/gnome-vfs2

PRINT_PLIST_AWK+=	/^@dirrm lib\/gnome-vfs-2.0\/modules/ \
				{ print "@comment in gnome-vfs2: " $$0; next; }
.endif	# GNOME_VFS2_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/fam/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
