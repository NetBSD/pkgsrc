# $NetBSD: Makefile,v 1.44 2020/03/10 22:09:21 wiz Exp $
#

GNOME_VFS_NAME=		cdda
PKGREVISION=		35
CATEGORIES=		audio

LICENSE=		gnu-lgpl-v2

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

EGFILES+=		modules/cdda-module.conf

INSTALLATION_DIRS+=	${EGDIR}/modules

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/cdda-module.conf ${DESTDIR}${EGDIR}/modules

.include "../../sysutils/gnome-vfs/Makefile.common"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
