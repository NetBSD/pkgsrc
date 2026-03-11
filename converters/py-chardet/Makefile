# $NetBSD: Makefile,v 1.38 2026/03/11 06:57:35 wiz Exp $
#
# There is controversy about the license change in version 7.0.0.
# Please don't update this package to 7+ for now.

DISTNAME=	chardet-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chardet/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/chardet/chardet
COMMENT=	Universal encoding detector for Python 3
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-exceptiongroup-[0-9]*:../../devel/py-exceptiongroup
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} chardetect chardetect-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
