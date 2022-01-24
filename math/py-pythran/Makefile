# $NetBSD: Makefile,v 1.7 2022/01/24 20:50:01 adam Exp $

DISTNAME=	pythran-0.11.0
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

USE_PKG_RESOURCES=	yes

post-extract:
	${RM} ${WRKSRC}/third_party/xsimd/config/xsimd_config.hpp.rej
	${RM} ${WRKSRC}/third_party/xsimd/config/xsimd_arch.hpp.rej
	${RM} ${WRKSRC}/third_party/xsimd/xsimd.hpp.rej

post-install:
.for bin in pythran pythran-config
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
