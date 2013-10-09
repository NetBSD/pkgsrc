# $NetBSD: Makefile,v 1.28 2013/10/09 17:39:14 wiz Exp $
#

GNOME_VFS_NAME=		smb
GNOME_VFS_FLAG=		samba
PKGREVISION=		19
CATEGORIES=		net

EGFILES+=		modules/smb-module.conf

CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib/samba

INSTALLATION_DIRS+=	${EGDIR}/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/smb-module.conf ${DESTDIR}${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../net/samba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
