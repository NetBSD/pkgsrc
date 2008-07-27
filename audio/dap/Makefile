# $NetBSD: Makefile,v 1.36 2008/07/27 08:45:58 obache Exp $

DISTNAME=	dap-2.1.5
CATEGORIES=	audio
MASTER_SITES=	# http://www.cee.hw.ac.uk/~richardk/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	scw@NetBSD.org
HOMEPAGE=	http://www.cee.hw.ac.uk/~richardk/
COMMENT=	Digital audio recording and processing package

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
INSTALLATION_DIRS+=	bin share/doc/dap
MAKE_FILE=		Makefile.netbsd
MAKE_ENV+=		X11PREFIX=${X11PREFIX:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${DESTDIR}${PREFIX}/bin/dap
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${WRKSRC}/FEATURES ${DESTDIR}${PREFIX}/share/doc/dap

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
