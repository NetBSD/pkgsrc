# $NetBSD: Makefile,v 1.1 2022/06/18 21:58:03 wiz Exp $

DISTNAME=	pydocstyle-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydocstyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/pydocstyle
COMMENT=	Python docstring style checker
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer-[0-9]*:../../textproc/py-snowballstemmer

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

post-extract:
	${CHMOD} go-w ${WRKSRC}/src/pydocstyle/data/*.txt

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pydocstyle pydocstyle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
