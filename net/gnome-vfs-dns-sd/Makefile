# $NetBSD: Makefile,v 1.1.1.1 2008/12/20 21:21:08 jmcneill Exp $
#

GNOME_VFS_NAME=		dns-sd
GNOME_VFS_FLAG=		avahi
CATEGORIES=		net

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../net/avahi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
