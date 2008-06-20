# $NetBSD: Makefile,v 1.12 2008/06/20 01:09:23 joerg Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"
PKGREVISION=	1
BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
