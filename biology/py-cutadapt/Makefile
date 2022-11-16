# $NetBSD: Makefile,v 1.10 2022/11/16 23:02:14 wiz Exp $

DISTNAME=	cutadapt-3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cutadapt/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://cutadapt.readthedocs.io/en/stable/
COMMENT=	Find and remove adapter sequences, primers, poly-A tails, etc
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
# needed for python 3.11 as of 3.5 release
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-dnaio>=0.5.0:../../biology/py-dnaio
DEPENDS+=	${PYPKGPREFIX}-xopen>=1.0.0:../../devel/py-xopen

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-xopen

USE_PKG_RESOURCES=	yes

# these files do not support python 3.11 in the 3.5 release
post-extract:
	${RM} ${WRKSRC}/src/cutadapt/*.c
	cd ${WRKSRC} && cythonize-${PYVERSSUFFIX} src/cutadapt/*.pyx

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cutadapt cutadapt-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
