# $NetBSD: Makefile,v 1.41 2019/07/21 22:25:31 wiz Exp $
#

GNOME_VFS_NAME=		smb
GNOME_VFS_FLAG=		samba
PKGREVISION=		32
CATEGORIES=		net

EGFILES+=		modules/smb-module.conf

CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib/samba

INSTALLATION_DIRS+=	${EGDIR}/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/smb-module.conf ${DESTDIR}${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../net/samba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
