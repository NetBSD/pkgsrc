# $NetBSD: Makefile,v 1.2 2003/03/28 21:14:34 wiz Exp $
#

MASTER_SITES=	# empty
DISTFILES=	# empty

COMMENT=	The "meta-package" for Amanda, a network backup system

DEPENDS+=	amanda-client-${VERS}:../../sysutils/amanda-dev-client
DEPENDS+=	amanda-server-${VERS}:../../sysutils/amanda-dev-server
DEPENDS+=	amanda-plot-${VERS}:../../sysutils/amanda-dev-plot

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-dev-common/Makefile.common"

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
