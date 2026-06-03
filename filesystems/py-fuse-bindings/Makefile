# $NetBSD: Makefile,v 1.29 2026/06/03 05:55:10 wiz Exp $

VERSION=		1.0.9
DISTNAME=		fuse_python-${VERSION}
PKGNAME=		${PYPKGPREFIX}-fuse-bindings-${VERSION}
CATEGORIES=		filesystems python
MASTER_SITES=		${MASTER_SITE_PYPI:=f/fuse-python/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/fuse-python
COMMENT=		Python bindings for FUSE and refuse
LICENSE=		gnu-lgpl-v2.1

TOOL_DEPENDS+=		${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_TOOLS+=		pkg-config

PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
PRINT_PLIST_AWK+=	{ gsub("${PYPKGPREFIX}-", "$${PYPKGPREFIX}-"); }

PYTHON_27_ACCEPTED=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
