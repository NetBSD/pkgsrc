# $NetBSD: Makefile,v 1.10 2004/09/16 17:41:26 minskim Exp $
#

DISTNAME=	ipcheck.217
PKGNAME=	ipcheck-0.217
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ipcheck.sourceforge.net/
COMMENT=	Python client for the dyndns service

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	#none
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}/ipcheck.py
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	ipcheck.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcheck.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
