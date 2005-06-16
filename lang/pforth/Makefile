# $NetBSD: Makefile,v 1.15 2005/06/16 06:58:00 jlam Exp $

DISTNAME=		pfthpc21
PKGNAME=		pforth-21
CATEGORIES=		lang
MASTER_SITES=		http://www.softsynth.com/pforth/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.softsynth.com/pforth/
COMMENT=		Portable ANS-like Forth

WRKSRC=			${WRKDIR}
USE_TOOLS+=		gmake
MAKEFILE=		${WRKSRC}/makefile

NOT_FOR_PLATFORM=	*-*-alpha  #segfaults when running ./pforth during build

INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/objects

post-patch:
	${MV} ${WRKSRC}/csrc/pf_main.c ${WRKSRC}/csrc/pf_main.c.dist
	${SED} -e 's:@PREFIX@:${PREFIX}:g' ${WRKSRC}/csrc/pf_main.c.dist \
	> ${WRKSRC}/csrc/pf_main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pforth ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pforth
	${INSTALL_DATA} ${WRKSRC}/pforth.dic ${PREFIX}/lib/pforth
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pforth
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${WRKSRC}/docs/* 		\
		${PREFIX}/share/doc/pforth/
	${INSTALL_DATA_DIR} ${PREFIX}/share/pforth
	${INSTALL_DATA} ${WRKSRC}/*.fth ${PREFIX}/share/pforth/
	${INSTALL_DATA_DIR} ${PREFIX}/share/pforth/utils
	${INSTALL_DATA}  ${WRKSRC}/utils/*.fth ${PREFIX}/share/pforth/utils/

.include "../../mk/bsd.pkg.mk"
