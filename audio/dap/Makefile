# $NetBSD: Makefile,v 1.33 2007/03/24 21:02:18 adam Exp $

DISTNAME=	dap-2.1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.cee.hw.ac.uk/~richardk/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	scw@NetBSD.org
HOMEPAGE=	http://www.cee.hw.ac.uk/~richardk/
COMMENT=	Digital audio recording and processing package

USE_LANGUAGES=		c c++
INSTALLATION_DIRS+=	share/doc/dap
MAKE_FILE=		Makefile.netbsd
MAKE_ENV+=		X11PREFIX=${X11PREFIX:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/dap
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${WRKSRC}/FEATURES ${PREFIX}/share/doc/dap

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
