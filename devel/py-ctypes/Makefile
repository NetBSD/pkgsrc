# $NetBSD: Makefile,v 1.3 2006/12/06 17:45:35 joerg Exp $

DISTNAME=	ctypes-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctypes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/theller/ctypes/
COMMENT=	Foreign Function Interface package for Python

PYTHON_VERSIONS_ACCEPTED=	24 23
PYDISTUTILSPKG=	yes

do-test:
	${PYTHONBIN} ${WRKSRC}/ctypes/test/runtests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
