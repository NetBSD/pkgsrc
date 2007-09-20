# $NetBSD: Makefile,v 1.2 2007/09/20 22:51:00 wiz Exp $
#

GNOME_VFS_NAME=		smb
GNOME_VFS_FLAG=		samba
CATEGORIES=		net

EGFILES+=		modules/smb-module.conf

CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib/samba

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/smb-module.conf ${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../net/samba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
