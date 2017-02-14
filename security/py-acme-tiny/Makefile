# $NetBSD: Makefile,v 1.1 2017/02/14 00:38:56 khorben Exp $

DISTNAME=	acme-tiny-0.0.20170214
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=diafygi/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/diafygi/acme-tiny/
COMMENT=	A tiny script to issue and renew TLS certs from Let's Encrypt
LICENSE=	mit

GITHUB_PROJECT=	acme-tiny
GITHUB_TAG=	daba51d37efd7c1f205f9da383b9b09968e30d29

NO_BUILD=	yes
INSTALLATION_DIRS=bin share/doc/${PYPKGPREFIX}-acme-tiny
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

REPLACE_PYTHON=	acme_tiny.py

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/acme_tiny.py ${DESTDIR}${PREFIX}/bin/acme_tiny
	${INSTALL} -m 0644 ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PYPKGPREFIX}-acme-tiny/README.md

.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
