# $NetBSD: Makefile,v 1.12 2006/03/06 00:18:14 wiz Exp $
#

GNOME_VFS2_NAME=	cdda
PKGREVISION=		3
CATEGORIES=		audio

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

EGFILES+=		modules/cdda-module.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/cdda-module.conf ${EGDIR}/modules

.include "../../sysutils/gnome-vfs2/Makefile.common"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
