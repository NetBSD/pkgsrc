# $NetBSD: Makefile,v 1.6 2005/04/12 20:12:02 jmmv Exp $
#

GNOME_VFS2_NAME=	cdda
PKGREVISION=		1
CATEGORIES=		audio

CPPFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia

EGFILES+=		modules/cdda-module.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/cdda-module.conf ${EGDIR}/modules

.include "../../sysutils/gnome-vfs2/Makefile.common"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
