# $NetBSD: Makefile,v 1.6 2010/02/10 19:17:42 joerg Exp $
#

DISTNAME=	Memo-1.9.5
PKGNAME=	rox-memo-1.9.5
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/159
COMMENT=	Reminds you about things

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

USE_TOOLS+=	pax

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/Memo
DIST_SUBDIR=	rox

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	AppRun

INSTALLATION_DIRS=	share/rox/Memo

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	post-patch
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/Memo

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
