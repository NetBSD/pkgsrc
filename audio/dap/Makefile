# $NetBSD: Makefile,v 1.11 2001/05/31 12:30:12 agc Exp $

DISTNAME=		dap-2.1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.cee.hw.ac.uk/~richardk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		scw@netbsd.org
HOMEPAGE=		http://www.cee.hw.ac.uk/~richardk/
COMMENT=		Digital audio recording and processing package

DEPENDS+=		xforms>=0.88nb1:../../x11/xforms

MAKEFILE=		Makefile.netbsd

MAKE_ENV+=		X11PREFIX=${X11PREFIX}

USE_X11BASE=		YES
USE_XPM=		YES

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dap
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${PREFIX}/share/doc/dap

.include "../../mk/bsd.pkg.mk"
