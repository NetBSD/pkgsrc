# $NetBSD: Makefile,v 1.21 2004/10/03 00:13:05 tv Exp $

DISTNAME=		dap-2.1.2
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		http://www.cee.hw.ac.uk/~richardk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		scw@NetBSD.org
HOMEPAGE=		http://www.cee.hw.ac.uk/~richardk/
COMMENT=		Digital audio recording and processing package

MAKEFILE=		Makefile.netbsd

MAKE_ENV+=		X11PREFIX=${X11PREFIX}

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dap
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${WRKSRC}/FEATURES ${PREFIX}/share/doc/dap

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
