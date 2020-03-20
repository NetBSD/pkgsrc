# $NetBSD: Makefile,v 1.14 2020/03/20 11:58:03 nia Exp $
#

DISTNAME=	Memo-1.9.5
PKGNAME=	rox-memo-1.9.5
PKGREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/159
COMMENT=	Reminds you about things

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/${DISTNAME}/Memo
DIST_SUBDIR=	rox

NO_BUILD=	yes

REPLACE_PYTHON=	AppRun

INSTALLATION_DIRS=	share/rox/Memo

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	pre-configure
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/Memo

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
