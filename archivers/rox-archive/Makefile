# $NetBSD: Makefile,v 1.6 2010/02/10 19:17:31 joerg Exp $
#

DISTNAME=	archive-2.0
PKGNAME=	rox-${DISTNAME}
PKGREVISION=	3
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
