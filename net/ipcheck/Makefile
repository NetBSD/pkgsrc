# $NetBSD: Makefile,v 1.7 2003/11/11 09:32:27 wiz Exp $
#

DISTNAME=	ipcheck.py
PKGNAME=	ipcheck-0.207
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ipcheck.sourceforge.net/
COMMENT=	Python client for the dyndns service

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	#none
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	ipcheck.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcheck.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
