# $NetBSD: Makefile,v 1.27 1999/09/06 18:17:27 bad Exp $
#

DISTNAME=	amanda-2.4.1p1
PKGNAME=	amanda-all-2.4.1p1
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.amanda.org/

DEPENDS+=	amanda-client-2.4.1p1:../../sysutils/amanda-client
DEPENDS+=	amanda-server-2.4.1p1:../../sysutils/amanda-server
DEPENDS+=	amanda-plot-2.4.1p1:../../sysutils/amanda-plot

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
