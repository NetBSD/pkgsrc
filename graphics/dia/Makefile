# $NetBSD: Makefile,v 1.75 2012/10/08 23:01:41 adam Exp $
#

.include "Makefile.common"

PKGREVISION=	8

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
