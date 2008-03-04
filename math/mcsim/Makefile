# $NetBSD: Makefile,v 1.19 2008/03/04 18:12:59 jlam Exp $

DISTNAME=	mcsim-4.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=mcsim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Monte Carlo Simulation software

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST
WRKSRC=		${WRKDIR}/mcsim

INSTALLATION_DIRS=	bin ${PKGINFODIR} share/doc/mcsim share/doc/html/mcsim

post-build:
	cd ${WRKSRC}/doc && makeinfo mcsim.texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mod/mod ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sim/mcsim ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/MCSim*	\
		${WRKSRC}/doc/mcsim.dvi ${DESTDIR}${PREFIX}/share/doc/mcsim/
	${INSTALL_DATA} ${WRKSRC}/doc/mcsim.html			\
		${DESTDIR}${PREFIX}/share/doc/html/mcsim
	cd ${WRKSRC}/doc; for f in mcsim mcsim-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};\
	done

.include "../../mk/bsd.pkg.mk"
