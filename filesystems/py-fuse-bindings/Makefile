# $NetBSD: Makefile,v 1.27 2026/06/02 23:52:47 gdt Exp $

#https://files.pythonhosted.org/packages/8f/41/1e372623fc863df2199f329d3548ef14376a9c1c7024743483547f166e5b/fuse_python-1.0.9.tar.gz
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

# \todo Explain what's going on and why.
.include "../../mk/fuse.buildlink3.mk"
#.include "../../filesystems/fuse/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
