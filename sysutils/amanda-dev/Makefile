# $NetBSD: Makefile,v 1.1.1.1 2002/05/02 13:28:15 bouyer Exp $
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
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
