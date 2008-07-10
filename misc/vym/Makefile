# $NetBSD: Makefile,v 1.2 2008/07/10 12:27:59 joerg Exp $
#

DISTNAME=		vym-1.8.1
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vym/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/vym/
COMMENT=		Mind-mapping software

USE_LANGUAGES+=		c c++
USE_TOOLS+=		perl:run bash:run

REPLACE_PERL+=		scripts/exportvym scripts/niceXML
REPLACE_BASH+=		scripts/update-bookmarks

SUBST_CLASSES+=		appdir
SUBST_STAGE.appdir=	post-patch
SUBST_FILES.appdir=	vym.pro
SUBST_SED.appdir=	-e 's|/usr/local/bin|${PREFIX}|' # sic

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake -o Makefile vym.pro

.include "../../x11/qt3/application.mk"

.include "../../mk/bsd.pkg.mk"
