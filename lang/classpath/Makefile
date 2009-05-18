# $NetBSD: Makefile,v 1.14 2009/05/18 13:15:19 wiz Exp $

.include "Makefile.common"

PKGREVISION=		1

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/bsd.pkg.mk"
