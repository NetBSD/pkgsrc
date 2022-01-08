# $NetBSD: Makefile,v 1.36 2022/01/08 14:43:09 tnn Exp $

DISTNAME=	arj-3.10.22
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arj.sourceforge.net/
COMMENT=	Open-source ARJ archiver
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		autoconf gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LD=${LD:Q}
CONFIGURE_SCRIPT=	${WRKSRC}/gnu/configure
MAKE_FILE=		makefile.gnu
MAKE_FLAGS+=		INSTALL_DIR=${INSTALL_PROGRAM_DIR:Q}

INSTALL_UNSTRIPPED=	yes # $LOCALBASE/bin/arj must have symbol table
ARJ_DOCSDIR=		${PREFIX}/share/doc/arj

pre-configure:
	${CP} -f ${WRKSRC}/environ.c ${WRKSRC}/environ.c.1
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < ${WRKSRC}/environ.c.1	\
			> ${WRKSRC}/environ.c
	${RM} -f ${WRKSRC}/environ.c.1
	cd ${WRKSRC}/gnu && autoconf

INSTALLATION_DIRS+=	${ARJ_DOCSDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/COPYING ${WRKSRC}/doc/debug.txt 	\
					${DESTDIR}${ARJ_DOCSDIR}
.for i in arjl.txt arjs.txt history.txt readme.txt unix.txt
	${INSTALL_DATA} ${WRKSRC}/resource/en/${i:Q} ${DESTDIR}${ARJ_DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
