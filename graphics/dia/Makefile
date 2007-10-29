# $NetBSD: Makefile,v 1.51 2007/10/29 22:34:32 drochner Exp $
#

.include "Makefile.common"

PKGREVISION=	2
USE_DIRS+=	xdg-1.1

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
