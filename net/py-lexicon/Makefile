# $NetBSD: Makefile,v 1.94 2024/12/10 06:34:37 adam Exp $

DISTNAME=	dns_lexicon-3.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dns_//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dns-lexicon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnalogJ/lexicon
COMMENT=	Manipulate DNS records on various DNS providers
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-dns>=2:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-otp>=2:../../security/py-otp
DEPENDS+=	${PYPKGPREFIX}-requests>=2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tldextract>=2:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-yaml>=3:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-vcrpy-[0-9]*:../../www/py-vcrpy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.6:../../devel/py-importlib-metadata
.endif

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} lexicon lexicon-${PYVERSSUFFIX} || ${TRUE}

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
