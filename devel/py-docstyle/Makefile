# $NetBSD: Makefile,v 1.5 2018/05/15 15:56:16 minskim Exp $

DISTNAME=	pydocstyle-2.1.1
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

post-extract:
	${CHMOD} go-w ${WRKSRC}/src/pydocstyle/data/*.txt

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pydocstyle pydocstyle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
