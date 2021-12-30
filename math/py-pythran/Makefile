# $NetBSD: Makefile,v 1.3 2021/12/30 13:05:38 adam Exp $

DISTNAME=	pythran-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pythran/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/serge-sans-paille/pythran
COMMENT=	Ahead of Time compiler for numeric kernels
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-beniget>=0.4.0:../../devel/py-beniget
DEPENDS+=	${PYPKGPREFIX}-gast>=0.5.0:../../devel/py-gast
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in pythran pythran-config
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
