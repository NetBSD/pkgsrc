# $NetBSD: Makefile,v 1.39 2026/03/11 14:03:30 adam Exp $
#
# There is controversy about the license change in version 7.0.0.
# Please don't update this package to 7+ for now.

DISTNAME=	chardet-7.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chardet/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/chardet/chardet
COMMENT=	Universal encoding detector for Python 3
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} chardetect chardetect-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
