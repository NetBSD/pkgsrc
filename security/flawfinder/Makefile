# $NetBSD: Makefile,v 1.15 2006/12/02 16:01:45 rillig Exp $

DISTNAME=	flawfinder-1.26
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dwheeler.com/flawfinder/
COMMENT=	Python program to find flaws in C/C++ programs

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	flawfinder
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
