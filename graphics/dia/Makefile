# $NetBSD: Makefile,v 1.53 2009/08/26 19:57:37 sno Exp $
#

.include "Makefile.common"

PKGREVISION=	3

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
