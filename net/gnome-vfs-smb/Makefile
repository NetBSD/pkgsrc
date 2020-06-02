# $NetBSD: Makefile,v 1.45 2020/06/02 08:24:30 adam Exp $
#

GNOME_VFS_NAME=		smb
GNOME_VFS_FLAG=		samba
PKGREVISION=		36
CATEGORIES=		net

EGFILES+=		modules/smb-module.conf

CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib/samba

INSTALLATION_DIRS+=	${EGDIR}/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/smb-module.conf ${DESTDIR}${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../net/samba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
