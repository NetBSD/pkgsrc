# $NetBSD: Makefile,v 1.1.1.1 2000/11/26 23:02:38 jtb Exp $

DISTNAME=	mcsim-4.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mcsim/}

MAINTAINER=	jtb@netbsd.org

WRKSRC=		${WRKDIR}/mcsim

INFO_FILES=	mcsim

do-build:
	@(cd ${WRKSRC}/mod && ${MAKE})
	@(cd ${WRKSRC}/sim && ${MAKE})
	@(cd ${WRKSRC}/sim && ${SH} Test_mcsim)
	@(cd ${WRKSRC}/doc && makeinfo mcsim.texinfo)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mod/mod ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sim/mcsim ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mcsim
	@(cd ${WRKSRC}/doc;						\
	for i in *.txt MCSim* mcsim.html mcsim.dvi;			\
	do								\
	${INSTALL_DATA} $$i ${PREFIX}/share/doc/mcsim;			\
	done;								\
	for i in mcsim mcsim-1 mcsim-2 mcsim-3;				\
	do								\
	${INSTALL_DATA} $$i ${PREFIX}/info;				\
	done)

.include "../../mk/bsd.pkg.mk"
