# $NetBSD: Makefile,v 1.1.1.1 2002/12/19 11:43:20 grant Exp $
#

DISTNAME=	roxirc-1.72
CATEGORIES=	chat
MASTER_SITES=	http://roxirc.lighter.net/download/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://roxirc.lighter.net/
COMMENT=	Graphical IRC client written in tcl/tk

USE_BUILDLINK2=	YES
NO_BUILD=	YES
NO_CONFIGURE=	YES

EXAMPLESDIR=	${PREFIX}/share/examples/roxirc

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

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
