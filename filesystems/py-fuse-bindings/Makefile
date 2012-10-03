# $NetBSD: Makefile,v 1.8 2012/10/03 16:08:33 asau Exp $
#

VERSION=		0.2.1
DISTNAME=		fuse-python-${VERSION}
PKGNAME=		${PYPKGPREFIX}-fuse-bindings-${VERSION}
CATEGORIES=		filesystems python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fuse/fuse-python}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/apps/mediawiki/fuse/index.php?title=FusePython
COMMENT=		Python bindings for FUSE and refuse
LICENSE=		gnu-lgpl-v2.1

EGG_NAME=		fuse_python-${VERSION}
PYDISTUTILSPKG=		yes
PY_PATCHLIST=		yes
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	share/examples/fuse-python

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/example/hello.py \
		${DESTDIR}${PREFIX}/share/examples/fuse-python/
	${INSTALL_SCRIPT} ${WRKSRC}/example/xmp.py \
		${DESTDIR}${PREFIX}/share/examples/fuse-python/

.include "../../lang/python/egg.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
