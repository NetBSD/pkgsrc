# $NetBSD: Makefile,v 1.2 2002/09/21 23:46:54 jlam Exp $
#

DISTNAME=	ipcheck.py
PKGNAME=	ipcheck-0.151
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://ipcheck.sourceforge.net/
COMMENT=	python client for the dyndns service

EXTRACT_SUFX=	#none
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
WRKSRC=		${WRKDIR}
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	ipcheck.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcheck.py ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
