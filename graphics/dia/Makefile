# $NetBSD: Makefile,v 1.50 2007/09/21 13:03:48 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	2
USE_DIRS+=	xdg-1.1

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../mk/bsd.pkg.mk"
