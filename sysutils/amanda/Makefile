# $NetBSD: Makefile,v 1.38 2004/11/12 12:13:44 mjl Exp $
#

DISTNAME=	amanda-2.4.4p4
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.amanda.org/
COMMENT=	The "meta-package" for Amanda, a network backup system

DEPENDS+=	amanda-client-2.4.4p2{,nb[0-9]*}:../../sysutils/amanda-client
DEPENDS+=	amanda-server-2.4.4p2{,nb[0-9]*}:../../sysutils/amanda-server
DEPENDS+=	amanda-plot-2.4.4p2{,nb[0-9]*}:../../sysutils/amanda-plot

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
