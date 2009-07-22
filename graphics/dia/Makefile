# $NetBSD: Makefile,v 1.52 2009/07/22 09:01:31 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	2

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
