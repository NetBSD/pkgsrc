# $NetBSD: Makefile,v 1.28 2016/03/08 15:19:16 wiz Exp $

DISTNAME=	virtualenv-15.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/v/virtualenv/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/virtualenv
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	virtualenv.py

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/virtualenv

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
