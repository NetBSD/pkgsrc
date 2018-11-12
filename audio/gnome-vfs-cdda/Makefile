# $NetBSD: Makefile,v 1.39 2018/11/12 03:51:41 ryoon Exp $
#

GNOME_VFS_NAME=		cdda
PKGREVISION=		30
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
