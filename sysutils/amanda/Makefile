# $NetBSD: Makefile,v 1.34 2003/06/04 18:21:48 jschauma Exp $
#

DISTNAME=	amanda-2.4.2p2
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.amanda.org/
COMMENT=	The "meta-package" for Amanda, a network backup system

DEPENDS+=	amanda-client-2.4.2p2:../../sysutils/amanda-client
DEPENDS+=	amanda-server-2.4.2p2:../../sysutils/amanda-server
DEPENDS+=	amanda-plot-2.4.2p2:../../sysutils/amanda-plot

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
