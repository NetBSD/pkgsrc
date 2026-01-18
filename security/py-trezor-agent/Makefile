# $NetBSD: Makefile,v 1.5 2026/01/18 09:23:58 wiz Exp $

DISTNAME=	trezor-agent-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=romanz/}
GITHUB_PROJECT=	trezor-agent
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/romanz/trezor-agent
COMMENT=	Hardware-based SSH/GPG/age agent
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-libagent>=0.14.0:../../security/py-libagent
DEPENDS+=	${PYPKGPREFIX}-trezor>=0.13:../../security/py-trezor

USE_LANGUAGES=	# none

WRKSRC=		${WRKDIR}/${DISTNAME}/agents/trezor

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
