# $NetBSD: Makefile,v 1.7 2022/01/04 20:53:01 wiz Exp $

DISTNAME=	pydocstyle-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydocstyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/pydocstyle
COMMENT=	Python docstring style checker
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer-[0-9]*:../../textproc/py-snowballstemmer

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
.endif

post-extract:
	${CHMOD} go-w ${WRKSRC}/src/pydocstyle/data/*.txt

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pydocstyle pydocstyle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
