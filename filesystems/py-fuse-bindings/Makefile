# $NetBSD: Makefile,v 1.28 2026/06/02 23:59:16 gdt Exp $

VERSION=		1.0.9
DISTNAME=		fuse_python-${VERSION}
PKGNAME=		${PYPKGPREFIX}-fuse-bindings-${VERSION}
CATEGORIES=		filesystems python
MASTER_SITES=		${MASTER_SITE_PYPI:=f/fuse-python/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/fuse-python
COMMENT=		Python bindings for FUSE and refuse
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config

EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS=	${EGDIR}
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
PRINT_PLIST_AWK+=	{ gsub("${PYPKGPREFIX}-", "$${PYPKGPREFIX}-"); }

PYTHON_27_ACCEPTED=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
