# $NetBSD: Makefile,v 1.11 2006/04/15 19:52:27 tonio Exp $

.include "Makefile.common"

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/bsd.pkg.mk"
