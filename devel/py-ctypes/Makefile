# $NetBSD: Makefile,v 1.2 2006/10/17 16:46:49 drochner Exp $

DISTNAME=	ctypes-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctypes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/theller/ctypes/
COMMENT=	Foreign Function Interface package for Python

PYDISTUTILSPKG=	yes

do-test:
	${PYTHONBIN} ${WRKSRC}/ctypes/test/runtests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
