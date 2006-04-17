# $NetBSD: Makefile,v 1.12 2006/04/17 14:52:11 wiz Exp $

.include "Makefile.common"

PKGREVISION=		1
BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/bsd.pkg.mk"
