# $NetBSD: Makefile,v 1.3 2026/10/16 18:15:06 adam Exp $

DISTNAME=	versioneer-0.29
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/versioneer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-versioneer/python-versioneer
COMMENT=	Version-string management for VCS-controlled trees
LICENSE=	unlicense

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	versioneer

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
