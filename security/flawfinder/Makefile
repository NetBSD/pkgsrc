# $NetBSD: Makefile,v 1.9 2004/06/23 16:19:41 snj Exp $

DISTNAME=	flawfinder-1.26
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dwheeler.com/flawfinder/
COMMENT=	Python program to find flaws in C/C++ programs

NO_BUILD=	# defined
PYTHON_PATCH_SCRIPTS= flawfinder

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
