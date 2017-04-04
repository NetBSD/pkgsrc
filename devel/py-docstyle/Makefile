# $NetBSD: Makefile,v 1.1 2017/04/04 13:31:37 wiz Exp $

DISTNAME=	pydocstyle-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydocstyle/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/PyCQA/pydocstyle
COMMENT=	Python docstring style checker
LICENSE=	mit

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pep257 pep257-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pydocstyle pydocstyle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
