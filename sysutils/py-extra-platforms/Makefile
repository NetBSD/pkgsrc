# $NetBSD: Makefile,v 1.1 2026/06/10 21:22:30 wiz Exp $

DISTNAME=	extra_platforms-13.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_GITHUB:=kdeldycke/}
GITHUB_PROJECT=	extra-platforms
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kdeldycke/extra-platforms/
COMMENT=	Detect architecture, OS, terminal, CI environment & AI coding agents
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build-[0-9]*:../../devel/py-uv-build

PY_RENAME_BINARIES=	extra-platforms

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
