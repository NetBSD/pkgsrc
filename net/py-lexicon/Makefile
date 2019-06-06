# $NetBSD: Makefile,v 1.35 2019/06/06 21:16:37 adam Exp $

DISTNAME=	dns-lexicon-3.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dns-//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dns-lexicon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnalogJ/lexicon
COMMENT=	Manipulate DNS records on various DNS providers
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tldextract-[0-9]*:../../net/py-tldextract
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.1.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.26.1:../../devel/py-test-xdist

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} lexicon lexicon-${PYVERSSUFFIX} || ${TRUE}

# Do not test providers
do-test:
	cd ${WRKSRC}/lexicon && pytest-${PYVERSSUFFIX} tests/test_*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
