# $NetBSD: Makefile,v 1.71 2012/06/14 07:43:59 sbd Exp $
#

.include "Makefile.common"

PKGREVISION=	4

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
