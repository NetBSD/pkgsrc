# $NetBSD: Makefile,v 1.9 2012/09/11 19:47:00 asau Exp $
#

DISTNAME=	archive-2.0
PKGNAME=	rox-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/74
COMMENT=	Simple archiver

# no real libraries there
DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

WRKSRC=		${WRKDIR}/${DISTNAME}/Archive
DIST_SUBDIR=	rox
USE_TOOLS+=	pax

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	AppRun tests/testall.py
REPLACE_SH=		Messages/dist Messages/update-po

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
