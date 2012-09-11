# $NetBSD: Makefile,v 1.18 2012/09/12 00:24:35 asau Exp $
#

GNOME_VFS_NAME=		cdda
PKGREVISION=		10
CATEGORIES=		audio

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

EGFILES+=		modules/cdda-module.conf

INSTALLATION_DIRS+=	${EGDIR}/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/cdda-module.conf ${DESTDIR}${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
