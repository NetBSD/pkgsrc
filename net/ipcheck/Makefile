# $NetBSD: Makefile,v 1.5 2003/07/17 22:51:15 grant Exp $
#

DISTNAME=	ipcheck.py
PKGNAME=	ipcheck-0.151
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://ipcheck.sourceforge.net/
COMMENT=	python client for the dyndns service

EXTRACT_SUFX=	#none
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	ipcheck.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcheck.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
