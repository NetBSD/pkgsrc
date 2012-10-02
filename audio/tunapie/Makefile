# $NetBSD: Makefile,v 1.16 2012/10/02 23:48:12 asau Exp $
#

DISTNAME=	tunapie-2.1.18
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tunapie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tunapie.sourceforge.net/
COMMENT=	Directory browser for Internet radio and TV streams
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.6:../../x11/py-wxWidgets

USE_LANGUAGES=	# none

SUBST_CLASSES+=		fixpaths
SUBST_STAGE.fixpaths=	do-configure
SUBST_FILES.fixpaths=	tunapie
SUBST_SED.fixpaths=	-e 's|python|${PYTHONBIN}|'
SUBST_SED.fixpaths+=	-e 's|/usr/local|${PREFIX}|g'

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	do-configure
SUBST_FILES.sysconfdir=	src/tuner.py
SUBST_SED.sysconfdir=	-e 's|/etc|${PKG_SYSCONFDIR}|g'

INSTALLATION_DIRS=	bin share/applications share/pixmaps share/tunapie
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

REPLACE_SH=		tunapie

# Refer ${WRKSRC}/install.sh for build&install.
do-build:
	${RUN}cd ${WRKSRC};${PYTHONBIN} src/compile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tunapie ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/*.py* ${DESTDIR}${PREFIX}/share/tunapie/
	${INSTALL_DATA} ${WRKSRC}/src/*.png ${DESTDIR}${PREFIX}/share/tunapie/
	${INSTALL_DATA} ${WRKSRC}/src/*.xpm ${DESTDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/tunapie.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/tunapie.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
