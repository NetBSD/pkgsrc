# $NetBSD: Makefile,v 1.22 2015/09/28 23:16:12 rodent Exp $

DISTNAME=	virtualenv-13.1.2
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/v/virtualenv/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/virtualenv
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	virtualenv.py

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/virtualenv

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
