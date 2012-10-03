# $NetBSD: Makefile,v 1.12 2012/10/03 00:02:44 asau Exp $
#

DISTNAME=	roxirc-1.8
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://roxirc.lighter.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://roxirc.lighter.net/
COMMENT=	Graphical IRC client written in tcl/tk

DEPENDS+=	tk-[0-9]*:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=	YES
NO_CONFIGURE=	YES

EXAMPLESDIR=	${PREFIX}/share/examples/roxirc

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded command names.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	roxirc
SUBST_SED.paths=	-e 's,wish8.3,wish,g'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roxirc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/roxirc
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${EXAMPLESDIR}/config
	${INSTALL_DATA} ${WRKSRC}/menus ${DESTDIR}${EXAMPLESDIR}/menus
	${INSTALL_DATA} ${WRKSRC}/bindings ${DESTDIR}${EXAMPLESDIR}/bindings
	${INSTALL_DATA} ${WRKSRC}/prefs ${DESTDIR}${EXAMPLESDIR}/prefs-initial
	${INSTALL_DATA} ${WRKSRC}/startup ${DESTDIR}${EXAMPLESDIR}/startup
	${INSTALL_DATA} ${WRKSRC}/help ${DESTDIR}${PREFIX}/share/doc/roxirc/help

.include "../../mk/bsd.pkg.mk"
