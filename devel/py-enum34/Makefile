# $NetBSD: Makefile,v 1.5 2016/04/17 09:47:44 wiz Exp $

DISTNAME=	enum34-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enum34/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/enum34
COMMENT=	Python module for enums like in python-3.4
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	33 27 # unnecessary on 34 and newer

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
