# $NetBSD: Makefile,v 1.49 2007/09/19 23:18:53 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	1
USE_DIRS+=	xdg-1.1

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../mk/bsd.pkg.mk"
