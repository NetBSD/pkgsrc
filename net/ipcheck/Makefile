# $NetBSD: Makefile,v 1.8 2004/01/20 12:22:19 agc Exp $
#

DISTNAME=	ipcheck.py
PKGNAME=	ipcheck-0.207
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ipcheck.sourceforge.net/
COMMENT=	Python client for the dyndns service

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	#none
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	ipcheck.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcheck.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
