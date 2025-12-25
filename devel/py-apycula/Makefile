# $NetBSD: Makefile,v 1.1 2025/12/25 17:01:49 ryoon Exp $

DISTNAME=	apycula-0.28
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
