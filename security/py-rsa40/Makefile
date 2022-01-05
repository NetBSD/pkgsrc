# $NetBSD: Makefile,v 1.3 2022/01/05 20:47:37 wiz Exp $

DISTNAME=	rsa-4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rsa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sybrenstuvel/python-rsa
COMMENT=	Pure-Python RSA implementation (for Python 2.x)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.3:../../security/py-asn1
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} pyrsa-decrypt pyrsa-decrypt-${PYVERSSUFFIX} && \
		${MV} pyrsa-encrypt pyrsa-encrypt-${PYVERSSUFFIX} && \
		${MV} pyrsa-keygen pyrsa-keygen-${PYVERSSUFFIX} && \
		${MV} pyrsa-priv2pub pyrsa-priv2pub-${PYVERSSUFFIX} && \
		${MV} pyrsa-sign pyrsa-sign-${PYVERSSUFFIX} && \
		${MV} pyrsa-verify pyrsa-verify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
