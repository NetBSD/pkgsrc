# $NetBSD: Makefile,v 1.15 2017/09/08 06:23:13 wiz Exp $

VERSION=		0.2.1
DISTNAME=		fuse-python-${VERSION}
PKGNAME=		${PYPKGPREFIX}-fuse-bindings-${VERSION}
CATEGORIES=		filesystems python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/fuse-python}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/fuse-python
COMMENT=		Python bindings for FUSE and refuse
LICENSE=		gnu-lgpl-v2.1

PYDISTUTILSPKG=		yes
PY_PATCHLIST=		yes
USE_TOOLS+=		pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.2.1

INSTALLATION_DIRS=	share/examples/fuse-python

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/example/hello.py \
		${DESTDIR}${PREFIX}/share/examples/fuse-python/
	${INSTALL_SCRIPT} ${WRKSRC}/example/xmp.py \
		${DESTDIR}${PREFIX}/share/examples/fuse-python/

.include "../../lang/python/egg.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
