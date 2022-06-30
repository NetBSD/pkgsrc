# $NetBSD: Makefile,v 1.18 2022/06/30 11:18:01 nia Exp $
#

DISTNAME=	archive-2.0
PKGNAME=	rox-${DISTNAME}
PKGREVISION=	8
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

REPLACE_PYTHON=	AppRun tests/testall.py
REPLACE_SH=	Messages/dist Messages/update-po

INSTALLATION_DIRS=	share/rox/Archive

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	pre-configure
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/Archive

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
