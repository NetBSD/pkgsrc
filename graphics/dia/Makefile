# $NetBSD: Makefile,v 1.68 2012/01/24 09:11:04 sbd Exp $
#

.include "Makefile.common"

PKGREVISION=	1

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
