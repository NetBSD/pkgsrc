# $NetBSD: Makefile,v 1.14 2002/07/24 12:27:43 agc Exp $

DISTNAME=		dap-2.1.2
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.cee.hw.ac.uk/~richardk/
EXTRACT_SUFX=		.tgz

MAINTAINER=		scw@netbsd.org
HOMEPAGE=		http://www.cee.hw.ac.uk/~richardk/
COMMENT=		Digital audio recording and processing package

MAKEFILE=		Makefile.netbsd

MAKE_ENV+=		X11PREFIX=${X11PREFIX}

USE_X11BASE=		yes
USE_BUILDLINK_ONLY=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dap
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${WRKSRC}/FEATURES ${PREFIX}/share/doc/dap

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/xforms/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
