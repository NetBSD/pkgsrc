# $NetBSD: Makefile,v 1.9 2001/02/16 13:30:34 wiz Exp $

DISTNAME=		dap-2.1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.cee.hw.ac.uk/~richardk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		scw@netbsd.org
HOMEPAGE=		http://www.cee.hw.ac.uk/~richardk/
COMMENT=		Digital audio recording and processing package

DEPENDS+=		xforms>=0.88nb1:../../x11/xforms

MAKEFILE=		Makefile.netbsd
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm32 *-*-i386 *-*-m68k *-*-sparc *-*-ns32k

USE_X11BASE=		YES
USE_XPM=		YES

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dap
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${PREFIX}/share/doc/dap

.include "../../mk/bsd.pkg.mk"
