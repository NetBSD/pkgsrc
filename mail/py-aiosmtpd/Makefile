# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:38 wiz Exp $

DISTNAME=	aiosmtpd-1.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiosmtpd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiosmtpd
COMMENT=	Asyncio based SMTP server
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.23.6:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=5.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14.0:../../devel/py-test-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${CHMOD} -R go-w ${WRKSRC}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} aiosmtpd aiosmtpd-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
