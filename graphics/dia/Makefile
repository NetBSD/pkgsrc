# $NetBSD: Makefile,v 1.54 2009/10/29 23:32:22 drochner Exp $
#

.include "Makefile.common"

PKGREVISION=	4

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
