# $NetBSD: Makefile,v 1.5 2001/04/28 23:59:20 jtb Exp $

DISTNAME=	mcsim-4.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mcsim/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Monte Carlo Simulation software

WRKSRC=		${WRKDIR}/mcsim
INFO_FILES=	mcsim

post-build:
	cd ${WRKSRC}/doc && makeinfo mcsim.texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mod/mod ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sim/mcsim ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mcsim
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/MCSim*	\
		${WRKSRC}/doc/mcsim.dvi ${PREFIX}/share/doc/mcsim/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mcsim
	${INSTALL_DATA} ${WRKSRC}/doc/mcsim.html			\
		${PREFIX}/share/doc/html/mcsim
	${INSTALL_DATA} mcsim mcsim-1 mcsim-2 mcsim-3 ${PREFIX}/info/

.include "../../mk/bsd.pkg.mk"
