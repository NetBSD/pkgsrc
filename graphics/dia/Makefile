# $NetBSD: Makefile,v 1.73.2.1 2012/10/03 12:07:57 spz Exp $
#

.include "Makefile.common"

PKGREVISION=	7

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
