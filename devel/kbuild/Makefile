# $NetBSD: Makefile,v 1.8 2022/06/28 11:31:45 wiz Exp $

KBUILDNAME=	kBuild
KBUILDVERMAJ=	0.1.9998
KBUILDVERMIN=	8
KBUILDVERSVN=	3127
#KBUILDVERFDR=	25

DISTNAME=	${KBUILDNAME}-r${KBUILDVERSVN}
PKGNAME=	kbuild-${KBUILDVERMAJ}.${KBUILDVERMIN}.r${KBUILDVERSVN}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://svn.netlabs.org/repos/kbuild/trunk

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.netlabs.org/kbuild/wiki/WikiStart
COMMENT=	Framework for writing simple makefiles for complex tasks
# but also various other licenses in 3rd party code
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pax lex gmake autoconf autoreconf automake autopoint perl

KBUILD_VERSION_PATCH=	${KBUILDVERMAJ:E}

INSTALL_ENV+=	KBUILD_VERBOSE=2

MAKE_ENV+=	KBUILD_LIB_SEARCH_PATHS="/lib /usr/lib ${X11BASE}/lib ${PREFIX}/lib"

LDFLAGS+=	-lutil
# honor CFLAGS and LDFLAGS
MAKE_ENV+=	TEMPLATE_BIN-KMK_CFLAGS=${CFLAGS:Q}
MAKE_ENV+=	TEMPLATE_BIN-KMK_LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=	TEMPLATE_BIN_CFLAGS=${CFLAGS:Q}
MAKE_ENV+=	TEMPLATE_BIN_LDFLAGS=${LDFLAGS:Q}

INSTALL_ENV+=	TEMPLATE_BIN_CFLAGS=${CFLAGS:Q}
INSTALL_ENV+=	TEMPLATE_BIN_LDFLAGS=${LDFLAGS:Q}
INSTALL_ENV+=	TEMPLATE_BIN-THREADED_CFLAGS=${CFLAGS:Q}
INSTALL_ENV+=	TEMPLATE_BIN-THREADED_LDFLAGS=${LDFLAGS:Q}
INSTALL_ENV+=	kObjCache_LDFLAGS=${LDFLAGS:Q}
INSTALL_ENV+=	kDepPre_LDFLAGS=${LDFLAGS:Q}
INSTALL_ENV+=	kmk_sed_LDFLAGS=${LDFLAGS:Q}
INSTALL_ENV+=	kmk_time_LDFLAGS=${LDFLAGS:Q}

.PHONY: fetch-with-svn
fetch-with-svn:
	${MKDIR} ${WRKDIR}; \
	cd ${WRKDIR}; \
	svn export -r${KBUILDVERSVN} ${MASTER_SITES}; \
	${MV} trunk ${DISTNAME}; \
	tar czf ${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}; \
	${MV} ${DISTNAME}${EXTRACT_SUFX} ${DISTDIR}; \
	${ECHO} do not forget to run "make makesum"

post-extract:
	${RUN} ${CP} ${FILESDIR}/SvnInfo.kmk ${WRKSRC}/

pre-build:
# Remove prebuilt files
	${RUN} cd ${WRKSRC} && rm -rf kBuild/bin/*

do-build:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ./kBuild/env.sh \
		--full ${GMAKE} -f bootstrap.gmk \
		KBUILD_VERBOSE=2 \
		KBUILD_VERSION_PATCH=${KBUILD_VERSION_PATCH} && \
	${SETENV} ${MAKE_ENV} ./kBuild/env.sh kmk \
		NIX_INSTALL_DIR=${PREFIX} \
		BUILD_TYPE=release \
		MY_INST_MODE=${NONBINMODE} \
		MY_INST_BIN_MODE=${BINMODE} \
		rebuild

do-install:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${INSTALL_ENV} ./kBuild/env.sh kmk \
		NIX_INSTALL_DIR=${PREFIX} \
		BUILD_TYPE=release \
		MY_INST_MODE=${NONBINMODE} \
		MY_INST_BIN_MODE=${BINMODE} \
		PATH_INS=${DESTDIR} \
		install

.include "../../mk/bsd.pkg.mk"
