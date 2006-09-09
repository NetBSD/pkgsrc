# $NetBSD: Makefile,v 1.31 2006/09/09 02:41:54 obache Exp $

DISTNAME=		dap-2.1.2
PKGREVISION=		6
CATEGORIES=		audio
MASTER_SITES=		# http://www.cee.hw.ac.uk/~richardk/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		scw@NetBSD.org
HOMEPAGE=		http://www.cee.hw.ac.uk/~richardk/
COMMENT=		Digital audio recording and processing package

MAKE_FILE=		Makefile.netbsd

MAKE_ENV+=		X11PREFIX=${X11PREFIX:Q}

USE_LANGUAGES=		c c++
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dap
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${WRKSRC}/FEATURES ${PREFIX}/share/doc/dap

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
