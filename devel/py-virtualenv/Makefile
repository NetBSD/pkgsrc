# $NetBSD: Makefile,v 1.37 2017/09/04 18:08:22 wiz Exp $

DISTNAME=	virtualenv-15.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/virtualenv
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

REPLACE_PYTHON=	virtualenv.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/virtualenv ${DESTDIR}${PREFIX}/bin/virtualenv-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
