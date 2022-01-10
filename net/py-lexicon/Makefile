# $NetBSD: Makefile,v 1.68 2022/01/10 19:46:34 adam Exp $

DISTNAME=	dns-lexicon-3.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dns-//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dns-lexicon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnalogJ/lexicon
COMMENT=	Manipulate DNS records on various DNS providers
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-requests>=2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tldextract>=3:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-yaml>=5:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.26.1:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} lexicon lexicon-${PYVERSSUFFIX} || ${TRUE}

# Do not test providers
do-test:
	cd ${WRKSRC}/lexicon && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests/test_*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
