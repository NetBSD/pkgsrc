# $NetBSD: Makefile,v 1.7 2021/08/24 08:33:53 adam Exp $

DISTNAME=	acme-tiny-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acme-tiny/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/diafygi/acme-tiny
COMMENT=	Tiny script to issue and renew TLS certs from Let's Encrypt
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	openssl-[0-9]*:../../security/openssl

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} acme-tiny acme-tiny-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
