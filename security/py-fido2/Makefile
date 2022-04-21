#	$NetBSD: Makefile,v 1.4 2022/04/21 11:00:01 wiz Exp $

DISTNAME=	fido2-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	python-fido2
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/python-fido2/
COMMENT=	Yubico FIDO U2F and FIDO 2.0 USB Python library
LICENSE=	2-clause-bsd AND apache-2.0 AND mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
