# $NetBSD: Makefile,v 1.13 2006/05/16 13:27:33 tonio Exp $

.include "Makefile.common"

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/bsd.pkg.mk"
