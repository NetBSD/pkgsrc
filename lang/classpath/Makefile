# $NetBSD: Makefile,v 1.15 2011/04/22 13:43:58 obache Exp $

.include "Makefile.common"

PKGREVISION=		2

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/bsd.pkg.mk"
