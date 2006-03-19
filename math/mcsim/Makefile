# $NetBSD: Makefile,v 1.17 2006/03/19 15:26:57 wiz Exp $

DISTNAME=	mcsim-4.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mcsim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Monte Carlo Simulation software

USE_TOOLS+=	makeinfo
INFO_FILES=	mcsim
WRKSRC=		${WRKDIR}/mcsim

INSTALLATION_DIRS=	bin info

post-build:
	cd ${WRKSRC}/doc && ${MAKEINFO} mcsim.texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mod/mod ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sim/mcsim ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mcsim
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/MCSim*	\
		${WRKSRC}/doc/mcsim.dvi ${PREFIX}/share/doc/mcsim/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mcsim
	${INSTALL_DATA} ${WRKSRC}/doc/mcsim.html			\
		${PREFIX}/share/doc/html/mcsim
	cd ${WRKSRC}/doc && ${INSTALL_DATA} mcsim ${PREFIX}/info/

.include "../../mk/bsd.pkg.mk"
