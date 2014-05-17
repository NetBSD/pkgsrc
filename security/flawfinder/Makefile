# $NetBSD: Makefile,v 1.23 2014/05/17 16:10:48 wiz Exp $

DISTNAME=	flawfinder-1.27
PKGREVISION=	4
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dwheeler.com/flawfinder/
COMMENT=	Python program to find flaws in C/C++ programs

NO_BUILD=		yes
REPLACE_PYTHON=	flawfinder
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
