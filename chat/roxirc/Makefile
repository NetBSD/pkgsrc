# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:26 joerg Exp $
#

DISTNAME=	roxirc-1.8
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://roxirc.lighter.net/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://roxirc.lighter.net/
COMMENT=	Graphical IRC client written in tcl/tk

DEPENDS+=	tk-[0-9]*:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=	YES
NO_CONFIGURE=	YES

EXAMPLESDIR=	${PREFIX}/share/examples/roxirc

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded command names."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	roxirc
SUBST_SED.paths=	-e 's,wish8.3,wish,g'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roxirc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/roxirc
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${EXAMPLESDIR}/config
	${INSTALL_DATA} ${WRKSRC}/menus ${EXAMPLESDIR}/menus
	${INSTALL_DATA} ${WRKSRC}/bindings ${EXAMPLESDIR}/bindings
	${INSTALL_DATA} ${WRKSRC}/prefs ${EXAMPLESDIR}/prefs-initial
	${INSTALL_DATA} ${WRKSRC}/startup ${EXAMPLESDIR}/startup
	${INSTALL_DATA} ${WRKSRC}/help ${PREFIX}/share/doc/roxirc/help

.include "../../mk/bsd.pkg.mk"
