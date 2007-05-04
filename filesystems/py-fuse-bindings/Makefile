# $NetBSD: Makefile,v 1.1.1.1 2007/05/04 19:51:52 agc Exp $
#

DISTNAME=		fuse-python-0.2pre1-20060720
PKGNAME=		${PYPKGPREFIX}-fuse-bindings-0.2pre1
CATEGORIES=		filesystems python
MASTER_SITES=		http://bsd.cenkes.org/myports/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bsd.cenkes.org/myports/
COMMENT=		Python bindings for FUSE and refuse

PYSETUP=		setup.py
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
USE_TOOLS+=		pkg-config

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fuse-python
	${INSTALL_SCRIPT} ${WRKSRC}/example/hello.py ${PREFIX}/share/examples/fuse-python/
	${INSTALL_SCRIPT} ${WRKSRC}/example/xmp.py ${PREFIX}/share/examples/fuse-python/

.include "../../lang/python/application.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
