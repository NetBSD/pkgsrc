# $NetBSD: Makefile,v 1.23 2007/12/22 23:41:01 tnn Exp $

DISTNAME=	arj-3.10.22
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arj.sourceforge.net/
COMMENT=	Open-source ARJ archiver

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		autoconf gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LD=${LD:Q}
CONFIGURE_SCRIPT=	${WRKSRC}/gnu/configure
MAKE_FILE=		makefile.gnu
MAKE_FLAGS+=		INSTALL_DIR=${INSTALL_PROGRAM_DIR:Q}

INSTALL_UNSTRIPPED=	yes # $LOCALBASE/bin/arj must have symbol table
ARJ_DOCSDIR=		${PREFIX}/share/doc/arj

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4.*)
CFLAGS+=	-fno-unit-at-a-time
.endif

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
.for i in arjl.txt arjs.txt history.txt readme.txt unix.txt
	${INSTALL_DATA} ${WRKSRC}/resource/en/${i:Q} ${ARJ_DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
