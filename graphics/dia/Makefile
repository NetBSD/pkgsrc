# $NetBSD: Makefile,v 1.87 2014/02/12 23:17:59 tron Exp $
#

.include "Makefile.common"

PKGREVISION=	20

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
