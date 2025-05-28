# $NetBSD: Makefile,v 1.24 2025/05/28 04:53:42 adam Exp $

DISTNAME=	pythran-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pythran/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythran.readthedocs.io/
COMMENT=	Ahead of Time compiler for numeric kernels
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-beniget>=0.4.0:../../devel/py-beniget
DEPENDS+=	${PYPKGPREFIX}-gast>=0.6.0:../../devel/py-gast
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
.for bin in pythran pythran-config
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
