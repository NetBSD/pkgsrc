# $NetBSD: Makefile,v 1.11 2022/01/13 19:31:24 wiz Exp $

DISTNAME=	acme-tiny-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acme-tiny/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/diafygi/acme-tiny
COMMENT=	Tiny script to issue and renew TLS certs from Let's Encrypt
LICENSE=	mit

DEPENDS+=	openssl-[0-9]*:../../security/openssl

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} acme-tiny acme-tiny-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
