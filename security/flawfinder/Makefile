# $NetBSD: Makefile,v 1.14 2006/03/04 21:30:33 jlam Exp $

DISTNAME=	flawfinder-1.26
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
