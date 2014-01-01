# $NetBSD: Makefile,v 1.35 2014/01/01 11:52:14 wiz Exp $

DISTNAME=	28107-kenigma-1.2.1
PKGNAME=	kenigma-1.2.1
PKGREVISION=	32
CATEGORIES=	emulators security
MASTER_SITES=	http://www.kde-apps.org/content/files/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kde-apps.org/content/show.php?content=28107
COMMENT=	Replica of the German enigma code machine used in WW2

WRKSRC=		${WRKDIR}/kenigma

NO_CONFIGURE=	yes
USE_LANGUAGES=	# none

APPDIR=		${KDEDIR}/share/kde/apps/kenigma

INSTALLATION_DIRS=	bin ${KDEDIR}/share/applications/kde

do-build:
	(cd ${WRKSRC}; \
	${ECHO} "#!/bin/sh"; \
	${ECHO} "cd ${APPDIR} && ${RUBY} main.rb") > ${WRKSRC}/kenigma

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kenigma ${DESTDIR}${KDEDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/kenigma.desktop \
		${DESTDIR}${KDEDIR}/share/applications/kde
	${INSTALL_DATA_DIR} ${DESTDIR}${APPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rb ${DESTDIR}${APPDIR}
	${INSTALL_DATA} ${WRKSRC}/kenigma.dtd ${DESTDIR}${APPDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${APPDIR}


.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../x11/kdebindings-ruby/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
