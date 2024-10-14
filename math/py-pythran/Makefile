# $NetBSD: Makefile,v 1.20 2024/10/14 06:45:51 wiz Exp $

DISTNAME=	pythran-0.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pythran/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythran.readthedocs.io/
COMMENT=	Ahead of Time compiler for numeric kernels
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-beniget>=0.4.0:../../devel/py-beniget
DEPENDS+=	${PYPKGPREFIX}-gast>=0.5.0:../../devel/py-gast
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-setuptools>=62:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
.for bin in pythran pythran-config
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
