# $NetBSD: Makefile,v 1.4 2003/12/05 18:08:33 kristerw Exp $
# FreeBSD Id: ports/archivers/arj/Makefile,v 1.2 2002/09/17 05:17:29 ijliao Exp

DISTNAME=	arj-3.10b
CATEGORIES=	archivers
MASTER_SITES=	http://testcase.newmail.ru/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://arj.sourceforge.net/
COMMENT=	Open-source ARJ

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/gnu/configure
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/gnu/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/gnu/config.sub
MAKEFILE=		makefile.gnu

ARJ_DOCSDIR=		${PREFIX}/share/doc/arj

pre-configure:
	${CP} -f ${WRKSRC}/environ.c ${WRKSRC}/environ.c.1
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/environ.c.1	\
			> ${WRKSRC}/environ.c
	${RM} -f ${WRKSRC}/environ.c.1
	cd ${WRKSRC}/gnu; ${AUTOCONF}

pre-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} -f ${MAKEFILE} ${MAKE_FLAGS} ${MAKE_ARGS} prepare)

post-install:
	${INSTALL_DATA_DIR} ${ARJ_DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/COPYING ${WRKSRC}/doc/debug.txt 	\
					${ARJ_DOCSDIR}
	for i in arjl.txt arjs.txt history.txt readme.txt unix.txt; do\
		${INSTALL_DATA} ${WRKSRC}/resource/en/$$i ${ARJ_DOCSDIR};\
		done

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
