# $NetBSD: Makefile,v 1.5 2009/02/09 22:56:21 joerg Exp $
#

DISTNAME=	archive-2.0
PKGNAME=	rox-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/74
COMMENT=	Simple archiver

# no real libraries there
DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/Archive
DIST_SUBDIR=	rox
USE_TOOLS+=	pax

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	AppRun tests/testall.py

INSTALLATION_DIRS=	share/rox/Archive

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	post-patch
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/Archive

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
