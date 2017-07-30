# $NetBSD: Makefile,v 1.2 2017/07/30 15:53:49 adam Exp $

DISTNAME=	pydocstyle-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydocstyle/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/PyCQA/pydocstyle
COMMENT=	Python docstring style checker
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer-[0-9]*:../../textproc/py-snowballstemmer

post-extract:
	${CHMOD} go-w ${WRKSRC}/src/pydocstyle/data/*.txt

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pydocstyle pydocstyle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
