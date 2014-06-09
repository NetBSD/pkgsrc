# $NetBSD: Makefile,v 1.89 2014/06/09 14:18:07 ryoon Exp $
#

.include "Makefile.common"

PKGREVISION=	22

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
