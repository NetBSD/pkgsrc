# $NetBSD: Makefile,v 1.16 2005/10/14 10:41:18 rillig Exp $

DISTNAME=	arj-3.10.21
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arj/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://arj.sourceforge.net/
COMMENT=	Open-source ARJ

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		autoconf gmake
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/gnu/configure
MAKEFILE=		makefile.gnu
MAKE_FLAGS+=		INSTALL_DIR=${INSTALL_PROGRAM_DIR:Q}
CONFIGURE_ENV+=		LD=${LD:Q}

INSTALL_UNSTRIPPED=	yes # $LOCALBASE/bin/arj must have symbol table
ARJ_DOCSDIR=		${PREFIX}/share/doc/arj

pre-configure:
	${CP} -f ${WRKSRC}/environ.c ${WRKSRC}/environ.c.1
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/environ.c.1	\
			> ${WRKSRC}/environ.c
	${RM} -f ${WRKSRC}/environ.c.1
	cd ${WRKSRC}/gnu && autoconf

post-install:
	${INSTALL_DATA_DIR} ${ARJ_DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/COPYING ${WRKSRC}/doc/debug.txt 	\
					${ARJ_DOCSDIR}
	for i in arjl.txt arjs.txt history.txt readme.txt unix.txt; do\
		${INSTALL_DATA} ${WRKSRC}/resource/en/$$i ${ARJ_DOCSDIR};\
		done

.include "../../mk/bsd.pkg.mk"
