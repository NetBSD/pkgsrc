# $NetBSD: Makefile,v 1.26 2026/06/02 23:41:28 gdt Exp $

VERSION=		1.0.4
DISTNAME=		fuse-python-${VERSION}
PKGNAME=		${PYPKGPREFIX}-fuse-bindings-${VERSION}
PKGREVISION=		3
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

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/example/hello.py \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example/xmp.py \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/python/wheel.mk"

# \todo Explain what's going on and why.
.include "../../mk/fuse.buildlink3.mk"
#.include "../../filesystems/fuse/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
