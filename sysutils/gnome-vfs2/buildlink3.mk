# $NetBSD: buildlink3.mk,v 1.2 2004/02/11 13:05:38 wiz Exp $
#
# This Makefile fragment is included by packages that use gnome-vfs2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_VFS2_BUILDLINK3_MK:=	${GNOME_VFS2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-vfs2
.endif

.if !empty(GNOME_VFS2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-vfs2
BUILDLINK_DEPENDS.gnome-vfs2+=		gnome-vfs2>=2.4.2nb2
BUILDLINK_PKGSRCDIR.gnome-vfs2?=	../../sysutils/gnome-vfs2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/fam/buildlink3.mk"

.endif # GNOME_VFS2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
