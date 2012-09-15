# $NetBSD: Makefile,v 1.73 2012/09/15 10:04:49 obache Exp $
#

.include "Makefile.common"

PKGREVISION=	6

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
