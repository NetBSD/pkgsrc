# $NetBSD: Makefile,v 1.82 2013/07/16 12:11:29 prlw1 Exp $
#

.include "Makefile.common"

PKGREVISION=	15

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
