# $NetBSD: Makefile,v 1.3 2001/02/25 22:14:19 jtb Exp $

DISTNAME=	mcsim-4.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mcsim/}

MAINTAINER=	jtb@netbsd.org
COMMENT=	Monte Carlo Simulation software

WRKSRC=		${WRKDIR}/mcsim
INFO_FILES=	mcsim

post-build:
	cd ${WRKSRC}/doc && makeinfo mcsim.texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mod/mod ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sim/mcsim ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mcsim
	@for f in ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/MCSim*	\
	${WRKSRC}/doc/mcsim.dvi; do				\
	i="${INSTALL_DATA} $$f ${PREFIX}/share/doc/mcsim/";	\
	${ECHO} $$i; $$i;					\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mcsim
	${INSTALL_DATA} ${WRKSRC}/doc/mcsim.html		\
	${PREFIX}/share/doc/html/mcsim
	@for f in mcsim mcsim-1 mcsim-2 mcsim-3; do		\
	i="${INSTALL_DATA} ${WRKSRC}/doc/$$f ${PREFIX}/info/";	\
	${ECHO} $$i; $$i;					\
	done

.include "../../mk/bsd.pkg.mk"
