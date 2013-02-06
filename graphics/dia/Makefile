# $NetBSD: Makefile,v 1.77 2013/02/06 23:22:25 jperkin Exp $
#

.include "Makefile.common"

PKGREVISION=	10

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
