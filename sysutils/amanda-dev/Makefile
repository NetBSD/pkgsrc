# $NetBSD: Makefile,v 1.3 2003/06/04 18:21:49 jschauma Exp $
#

MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	The "meta-package" for Amanda, a network backup system

DEPENDS+=	amanda-client-${VERS}:../../sysutils/amanda-dev-client
DEPENDS+=	amanda-server-${VERS}:../../sysutils/amanda-dev-server
DEPENDS+=	amanda-plot-${VERS}:../../sysutils/amanda-dev-plot

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-dev-common/Makefile.common"

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
