# $NetBSD: Makefile,v 1.6 2003/07/21 17:10:45 martti Exp $
#

DISTNAME=	ipcheck.py
PKGNAME=	ipcheck-0.151
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ipcheck.sourceforge.net/
COMMENT=	Python client for the dyndns service

EXTRACT_SUFX=	#none
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	ipcheck.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcheck.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
