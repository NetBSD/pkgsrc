# $NetBSD: Makefile,v 1.2 2004/04/15 20:10:43 jmmv Exp $
#

GNOME_VFS2_NAME=	smb
GNOME_VFS2_FLAG=	samba
CATEGORIES=		net

EGFILES+=		modules/smb-module.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/smb-module.conf ${EGDIR}/modules

.include "../../sysutils/gnome-vfs2/Makefile.common"

.include "../../net/samba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
