# $NetBSD: Makefile,v 1.3 2017/05/26 09:00:37 adam Exp $

DISTNAME=	cryptography_vectors-1.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cryptography_vectors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cryptography-vectors/
COMMENT=	Cryptographic test vectors
LICENSE=	apache-2.0 OR modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
#DEPENDS+=	${PYPKGPREFIX}-cffi>=1.8.2:../../devel/py-cffi
#DEPENDS+=	${PYPKGPREFIX}-cparser>=2.10:../../devel/py-cparser
#DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
#DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
## actually, TEST_DEPENDS
#BUILD_DEPENDS+=	${PYPKGPREFIX}-iso8601-[0-9]*:../../time/py-iso8601
#BUILD_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
#BUILD_DEPENDS+=	${PYPKGPREFIX}-requests>=0.8:../../devel/py-requests
#BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=0.8:../../devel/py-test
#
#.include "../../lang/python/pyversion.mk"
#
#.if ${PYPKGPREFIX} == "py27"
#DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
#DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
#.endif

#do-test:
#	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
#.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
