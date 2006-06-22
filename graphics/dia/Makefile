# $NetBSD: Makefile,v 1.45 2006/06/22 10:05:36 joerg Exp $
#

.include "Makefile.common"

USE_TOOLS+=	msgfmt

USE_DIRS+=	xdg-1.1

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../mk/bsd.pkg.mk"
