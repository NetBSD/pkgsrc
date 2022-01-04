# $NetBSD: Makefile,v 1.12 2022/01/04 20:53:07 wiz Exp $

DISTNAME=	python-gflags-3.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gflags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/python-gflags
COMMENT=	Python equivalent of gflags, a commandline flag implementation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

REPLACE_PYTHON+=		*.py
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/gflags2man.py ${DESTDIR}${PREFIX}/bin/gflags2man${PYVERSSUFFIX}.py 
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/gflags2man${PYVERSSUFFIX}.py 

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
