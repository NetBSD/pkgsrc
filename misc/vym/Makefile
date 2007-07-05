# $NetBSD: Makefile,v 1.1.1.1 2007/07/05 19:36:37 agc Exp $
#

DISTNAME=		vym-1.8.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vym/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/vym/
COMMENT=		Mind-mapping software

USE_LANGUAGES+=		c c++

SUBST_CLASSES+=		appdir
SUBST_STAGE.appdir=	post-patch
SUBST_FILES.appdir=	vym.pro
SUBST_SED.appdir=	-e 's|/usr/local/bin|${PREFIX}|' # sic

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake -o Makefile vym.pro

.include "../../x11/qt3/application.mk"

.include "../../mk/bsd.pkg.mk"
