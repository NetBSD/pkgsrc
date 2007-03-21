# $NetBSD: Makefile,v 1.47 2007/03/21 12:05:46 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=	1

USE_DIRS+=	xdg-1.1

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../mk/bsd.pkg.mk"
