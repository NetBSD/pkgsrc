# $NetBSD: Makefile,v 1.7 2026/03/02 19:42:39 js Exp $

LIBAGENT_VER=	0.16.0
DISTNAME=	trezor-agent-${LIBAGENT_VER}
PKGNAME=	${PYPKGPREFIX}-trezor-agent-0.13.0
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=romanz/}
GITHUB_PROJECT=	trezor-agent
GITHUB_TAG=	libagent/${LIBAGENT_VER}

WRKSRC=		${WRKDIR}/trezor-agent-libagent-${LIBAGENT_VER}/agents/trezor

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/romanz/trezor-agent
COMMENT=	Hardware-based SSH/GPG/age agent
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-libagent>=${LIBAGENT_VER}:../../security/py-libagent
DEPENDS+=	${PYPKGPREFIX}-trezor>=0.20:../../security/py-trezor

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
