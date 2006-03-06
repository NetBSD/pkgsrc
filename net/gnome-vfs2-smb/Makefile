# $NetBSD: Makefile,v 1.8 2006/03/06 00:18:22 wiz Exp $
#

GNOME_VFS2_NAME=	smb
GNOME_VFS2_FLAG=	samba
PKGREVISION=		3
CATEGORIES=		net

EGFILES+=		modules/smb-module.conf

CONFIGURE_ARGS+=	--with-samba-libs=${BUILDLINK_PREFIX.samba}/lib/samba

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/smb-module.conf ${EGDIR}/modules

.include "../../sysutils/gnome-vfs2/Makefile.common"

.include "../../net/samba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
