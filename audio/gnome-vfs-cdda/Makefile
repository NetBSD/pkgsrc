# $NetBSD: Makefile,v 1.6 2010/09/14 11:03:10 wiz Exp $
#

GNOME_VFS_NAME=		cdda
PKGREVISION=		1
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
