# $NetBSD: Makefile,v 1.24 2015/03/11 00:51:06 mef Exp $

DISTNAME=	flawfinder-1.31
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dwheeler.com/flawfinder/
COMMENT=	Python program to find flaws in C/C++ programs
LICENSE=	gnu-gpl-v2

NO_BUILD=		yes
REPLACE_PYTHON=	flawfinder
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
