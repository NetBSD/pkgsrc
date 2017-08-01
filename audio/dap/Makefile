# $NetBSD: Makefile,v 1.47 2017/08/01 16:47:35 wiz Exp $

DISTNAME=	dap-2.1.5
PKGREVISION=	4
CATEGORIES=	audio
#MASTER_SITES=	# http://www.cee.hw.ac.uk/~richardk/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cee.hw.ac.uk/~richardk/
COMMENT=	Digital audio recording and processing package

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
INSTALLATION_DIRS+=	bin share/doc/dap
MAKE_FILE=		Makefile.netbsd
MAKE_ENV+=		OTHER_INCLUDE_DIR=.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${DESTDIR}${PREFIX}/bin/dap
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${WRKSRC}/FEATURES ${DESTDIR}${PREFIX}/share/doc/dap

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
