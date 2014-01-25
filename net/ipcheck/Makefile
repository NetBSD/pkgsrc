# $NetBSD: Makefile,v 1.21 2014/01/25 10:45:20 wiz Exp $
#

DISTNAME=	ipcheck.233
PKGNAME=	ipcheck-0.233
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipcheck.sourceforge.net/
COMMENT=	Python client for the dyndns service

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	#none
EXTRACT_CMD=	${CP} "$${extract_file}" ipcheck.py
NO_BUILD=	yes

REPLACE_PYTHON=	ipcheck.py
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcheck.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
