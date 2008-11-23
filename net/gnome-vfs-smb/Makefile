# $NetBSD: Makefile,v 1.4 2008/11/23 13:45:33 jmcneill Exp $
#

PKGREVISION=		1

GNOME_VFS_NAME=		smb
GNOME_VFS_FLAG=		samba
CATEGORIES=		net

PKG_DESTDIR_SUPPORT=	user-destdir

EGFILES+=		modules/smb-module.conf

CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib/samba

INSTALLATION_DIRS+=	${EGDIR}/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/smb-module.conf ${DESTDIR}${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../net/samba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
