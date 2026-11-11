# $NetBSD: Makefile,v 1.71 2026/11/11 11:52:51 wiz Exp $

DISTNAME=	subvertpy-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel scm python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/subvertpy/}

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	https://launchpad.net/subvertpy
COMMENT=	Alternative Python bindings for Subversion
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

MAKE_ENV+=	SVN_PREFIX=${BUILDLINK_PREFIX.subversion-base}

PY_RENAME_BINARIES=	subvertpy-fast-export

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
