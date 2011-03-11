# $NetBSD: Makefile,v 1.4 2011/03/11 11:29:42 zafer Exp $
#

DISTNAME=		fuse-python-0.2pre1-20060720
PKGNAME=		${PYPKGPREFIX}-fuse-bindings-0.2pre1
PKGREVISION=		2
CATEGORIES=		filesystems python
MASTER_SITES=		# http://bsd.cenkes.org/myports/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bsd.cenkes.org/myports/
COMMENT=		Python bindings for FUSE and refuse

PYDISTUTILSPKG=		yes
PY_PATCHLIST=		yes
USE_TOOLS+=		pkg-config
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	share/examples/fuse-python

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/example/hello.py \
		${DESTDIR}${PREFIX}/share/examples/fuse-python/
	${INSTALL_SCRIPT} ${WRKSRC}/example/xmp.py \
		${DESTDIR}${PREFIX}/share/examples/fuse-python/

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
