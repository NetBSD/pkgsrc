# $NetBSD: Makefile,v 1.13 2006/02/15 13:43:35 rillig Exp $

DISTNAME=	flawfinder-1.26
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dwheeler.com/flawfinder/
COMMENT=	Python program to find flaws in C/C++ programs

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	flawfinder
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/flawfinder ${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/flawfinder.1 ${PREFIX:Q}/man/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
