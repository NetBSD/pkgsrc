# $NetBSD: Makefile,v 1.56 2021/03/18 09:04:16 adam Exp $

DISTNAME=	dns-lexicon-3.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dns-//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dns-lexicon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnalogJ/lexicon
COMMENT=	Manipulate DNS records on various DNS providers
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-future>=0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests>=2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tldextract>=3:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-yaml>=5:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.26.1:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} lexicon lexicon-${PYVERSSUFFIX} || ${TRUE}

# Do not test providers
do-test:
	cd ${WRKSRC}/lexicon && pytest-${PYVERSSUFFIX} tests/test_*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
