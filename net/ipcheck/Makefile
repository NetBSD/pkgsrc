# $NetBSD: Makefile,v 1.12 2006/01/21 18:57:41 jlam Exp $
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
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ipcheck.py
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	ipcheck.py
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcheck.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
