# $NetBSD: Makefile,v 1.1.1.1 2002/07/14 13:02:23 wiz Exp $
#

DISTNAME=	flawfinder-1.20
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

.include "../../lang/python/application.buildlink.mk"
.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
