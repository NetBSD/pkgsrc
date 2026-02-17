# $NetBSD: Makefile,v 1.2 2026/02/17 11:12:06 adam Exp $

DISTNAME=	apycula-0.29
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apycula/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/apicula
COMMENT=	Open Source tools for Gowin FPGAs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-crc-[0-9]*:../../devel/py-crc

USE_LANGUAGES=	# none

post-install:
.for c in pack pll unpack
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} gowin_${c} gowin_${c}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
