# $NetBSD: Makefile,v 1.14 2012/02/06 12:39:23 wiz Exp $
#

GNOME_VFS_NAME=		cdda
PKGREVISION=		7
CATEGORIES=		audio

PKG_DESTDIR_SUPPORT=	user-destdir

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

EGFILES+=		modules/cdda-module.conf

INSTALLATION_DIRS+=	${EGDIR}/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/cdda-module.conf ${DESTDIR}${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
