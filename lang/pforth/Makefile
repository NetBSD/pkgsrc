# $NetBSD: Makefile,v 1.2 2001/02/17 09:07:25 agc Exp $

DISTNAME=		pfthunix19
PKGNAME=		pforth-19
CATEGORIES=		lang
MASTER_SITES=		http://www.softsynth.com/pforth/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.softsynth.com/pforth/
COMMENT=		Portable ANS-like Forth

WRKSRC=			${WRKDIR}/pforth
USE_GMAKE=		YES
MAKEFILE=		${WRKSRC}/makefile

post-extract:
	${MKDIR} ${WRKSRC}/objects

post-patch:
	@for i in ${WRKSRC}/csrc/pf_main.c; do \
		${SED} -e 's:@PREFIX@:${PREFIX}:g' \
		< $$i > $$i.tmp && ${MV} -f $$i.tmp $$i; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pforth ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pforth
	${INSTALL_DATA} ${WRKSRC}/pforth.dic ${PREFIX}/lib/pforth
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pforth
	@for d in ${WRKSRC}/readme.txt ${WRKSRC}/docs/*; do \
		c="${INSTALL_DATA} $$d ${PREFIX}/share/doc/pforth/"; \
		${ECHO} $$c; $$c; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/pforth
	@for f in ${WRKSRC}/*.fth; do \
		c="${INSTALL_DATA} $$f ${PREFIX}/share/pforth/"; \
		${ECHO} $$c; $$c; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/pforth/utils
	@for u in  ${WRKSRC}/utils/*.fth; do \
		c="${INSTALL_DATA} $$u ${PREFIX}/share/pforth/utils/"; \
		${ECHO} $$c; $$c; \
	done

.include "../../mk/bsd.pkg.mk"
