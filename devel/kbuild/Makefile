# $NetBSD: Makefile,v 1.1 2016/07/08 09:42:53 kamil Exp $
#

KBUILDNAME=	kBuild
KBUILDVERMAJ=	0.1.9998
KBUILDVERMIN=	8
KBUILDVERSVN=	2814
KBUILDVERFDR=	25

DISTNAME=	${KBUILDNAME}-${KBUILDVERMAJ}-${KBUILDVERMIN}.r${KBUILDVERSVN}.fc${KBUILDVERFDR}
PKGNAME=	${KBUILDNAME:tl}-${KBUILDVERMAJ}.${KBUILDVERMIN}.${KBUILDVERSVN}.${KBUILDVERFDR}
CATEGORIES=	devel
MASTER_SITES=	http://dl.fedoraproject.org/pub/fedora/linux/development/rawhide/Everything/source/tree/Packages/k/
EXTRACT_SUFX=	.src.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.netlabs.org/kbuild/wiki/WikiStart
COMMENT=	Framework for writing simple makefiles for complex tasks
# but also various other licenses in 3rd party code
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${KBUILDNAME}

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	pax lex gmake autoconf autoreconf automake autopoint

KBUILD_VERSION_PATCH=	${KBUILDVERMAJ:E}

INSTALL_ENV+=	KBUILD_VERBOSE=2

MAKE_ENV+=	KBUILD_LIB_SEARCH_PATHS="/lib /usr/lib ${X11BASE}/lib ${PREFIX}/lib"

post-extract:
	${RUN} cd ${WRKDIR} && ${EXTRACTOR} ${KBUILDNAME}-r${KBUILDVERSVN}.tar.gz
	${RUN} ${CP} ${FILESDIR}/strtofflags.c ${WRKSRC}/src/kmk/strtofflags.c

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
