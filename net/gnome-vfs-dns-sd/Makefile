# $NetBSD: Makefile,v 1.2 2009/08/26 19:58:09 sno Exp $
#

GNOME_VFS_NAME=		dns-sd
GNOME_VFS_FLAG=		avahi
PKGREVISION=		1
CATEGORIES=		net

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../net/avahi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
