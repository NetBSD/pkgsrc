# $NetBSD: Makefile,v 1.4 2003/03/09 18:11:05 wiz Exp $
#

DISTNAME=	flawfinder-1.22
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dwheeler.com/flawfinder/
COMMENT=	python program to find flaws in C/C++ programs

PYTHON_PATCH_SCRIPTS= flawfinder
PY_PATCHPLIST=  yes

NO_CONFIGURE=	# defined
NO_BUILD=	# defined
MAKEFILE=	makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
