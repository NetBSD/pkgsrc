# $NetBSD: Makefile,v 1.2 2025/03/08 12:34:43 wiz Exp $

DISTNAME=	trezor-agent-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=romanz/}
GITHUB_PROJECT=	trezor-agent
GITHUB_TAG=	v${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${DISTNAME}/agents/trezor

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/romanz/trezor-agent
COMMENT=	Hardware-based SSH/GPG/age agent
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-libagent>=0.14.0:../../security/py-libagent
DEPENDS+=	${PYPKGPREFIX}-trezor>=0.13:../../security/py-trezor

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
