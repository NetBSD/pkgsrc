# $NetBSD: Makefile,v 1.6 2000/02/29 16:57:45 scw Exp $

DISTNAME=		dap-2.1.1
CATEGORIES=		audio
MASTER_SITES=		http://www.cee.hw.ac.uk/~richardk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		scw@netbsd.org
HOMEPAGE=		http://www.cee.hw.ac.uk/~richardk/

DEPENDS+=		xpm-*:../../graphics/xpm
DEPENDS+=		xforms-0.88:../../x11/xforms

MAKEFILE=		Makefile.netbsd
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm32 *-*-i386 *-*-m68k *-*-sparc *-*-ns32k

USE_X11BASE=		YES

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dap
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${PREFIX}/share/doc/dap

.include "../../mk/bsd.pkg.mk"
