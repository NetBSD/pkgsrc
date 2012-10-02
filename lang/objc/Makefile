# $NetBSD: Makefile,v 1.16 2012/10/02 20:11:46 asau Exp $

DISTNAME=	objc-3.2.10
CATEGORIES=	lang
MASTER_SITES=	http://users.pandora.be/stes/
DISTFILES=	${DIST_BS}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.pandora.be/stes/compiler.html
COMMENT=	Portable Object Compiler

DIST_BS=	objc-bootstrap-3.2.8
WRKSRC_BS=	${WRKDIR}/${DIST_BS}

MAKE_JOBS_SAFE=		no

CONFIGURE_DIRS=		${WRKSRC_BS} ${WRKSRC}
CONFIG_GUESS_OVERRIDE=	${WRKSRC_BS}/util/config.guess util/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC_BS}/util/config.sub util/config.sub
BUILD_DIRS=		${WRKSRC}
PREPEND_PATH+=		${WRKSRC_BS}
BUILD_TARGET=		default

USE_TOOLS+=		lex yacc
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		mflags
SUBST_STAGE.mflags=	post-extract
SUBST_MESSAGE.mflags=	Changing 'MFLAGS' to 'MMFLAGS'
SUBST_SED.mflags=	-e 's,MFLAGS,MMFLAGS,g'
SUBST_FILES.mflags=	configure configure.in manual.html \
			*/Makefile* src/*/Makefile*

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	post-configure
SUBST_MESSAGE.mandir=	Making mandir=${PKGMANDIR} 
SUBST_SED.mandir=	-e '/$$(TAR)/s,man,${PKGMANDIR},' 
SUBST_FILES.mandir=	Makefile

pre-configure:
	${ECHO} >> ${WRKSRC_BS}/configure \
	'${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} ${BUILD_TARGET}'

post-configure:
	${LN} -s . ${WRKSRC_BS}/bin
	${SED} < ${WRKSRC_BS}/objc > ${WRKDIR}/oc.tmp \
		-e 's|${PREFIX}|${WRKSRC_BS}|g'
	${MV} ${WRKDIR}/oc.tmp ${WRKSRC_BS}/objc
	${CHMOD} +x ${WRKSRC_BS}/objc

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGMANDIR:M*/*)
post-build:
	${MKDIR} ${WRKSRC}/${PKGMANDIR:H}
	${MV} ${WRKSRC}/man ${WRKSRC}/${PKGMANDIR}
.endif

.include "../../mk/bsd.pkg.mk"
