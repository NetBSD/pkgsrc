# $NetBSD: Makefile,v 1.2 2018/04/16 12:19:36 fhajny Exp $

DISTNAME=	josepy-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=certbot/}
GITHUB_PROJECT=	josepy
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/certbot/josepy/
COMMENT=	JOSE protocol implementation in Python using cryptography
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.8:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jws \
		${DESTDIR}${PREFIX}/bin/jws${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
