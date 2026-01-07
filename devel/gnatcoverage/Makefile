# $NetBSD: Makefile,v 1.2 2026/01/07 23:33:45 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-25.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatcoverage
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatcoverage
COMMENT=	Tool to analyze and report program coverage
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++ ada

USE_TOOLS+=	gmake bison
USE_LIBTOOL=	yes
TOOLS_BROKEN+=	perl

MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Set version in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	tools/gnatcov/version.ads
SUBST_SED.version=	-e "s,development-tree,${GITHUB_TAG},"

# We need binutil's static libraries only but pkgsrc's package
# does not install two required static libraries:
# - libintl.a (it is not the same as builtin or pkgsrc's);
# - libiberty.a (internal GCC's library).
# This prevents programs that use static bfd.a from linking.
# So we use inplace build of binutils.

#.include "../../devel/binutils/inplace.mk"
BINUTILS_PREFIX=	${PREFIX}/${MACHINE_GNU_PLATFORM}
LIB_PATH=		/lib:/usr/lib
.if exists(/usr/lib64)
LIB_PATH:=		/usr/lib64:${LIB_PATH}
.endif
.if exists(/lib64)
LIB_PATH:=		/lib64:${LIB_PATH}
.endif

BINUTILS_DISTNAME=	binutils
post-fetch: fetch-inplace-binutils

post-extract: extract-inplace-binutils

.PHONY: fetch-inplace-binutils
fetch-inplace-binutils:
	@${STEP_MSG} Fetching in-place binutils
	${RUN}cd ../../devel/binutils && \
	    ${MAKE} WRKDIR=${WRKDIR}/.devel.binutils \
		EXTRACT_DIR=${WRKDIR} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
		SKIP_DEPENDS=YES \
		checksum

.PHONY: extract-inplace-binutils
extract-inplace-binutils:
	@${STEP_MSG} Extracting in-place binutils
	${RUN}cd ../../devel/binutils && \
	    ${MAKE} WRKDIR=${WRKDIR}/.devel.binutils \
		EXTRACT_DIR=${WRKDIR} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
		SKIP_DEPENDS=YES \
		patch
	${RUN}${MV} ${WRKDIR}/binutils-* ${WRKDIR}/${BINUTILS_DISTNAME}

.include "../../math/isl/inplace.mk"
.include "../../devel/gmp/inplace.mk"
.include "../../math/mpcomplex/inplace.mk"
.include "../../math/mpfr/inplace.mk"

# TOML library builds with GNAT 13 by default, to build it with
# GNAT 14 for this package, we need inplacing
CREATE_INPLACE_BUILD_TARGETS=	static
.include "../../textproc/ada-toml/inplace.mk"

# First make TOML library in-place
pre-configure: ${INPLACE_BUILD_TARGETS}
# Second make binutils in-place with inplaced maths
	${MV} ${WRKSRC}/isl ${WRKDIR}/${BINUTILS_DISTNAME}/
	${MV} ${WRKSRC}/gmp ${WRKDIR}/${BINUTILS_DISTNAME}/
	${MV} ${WRKSRC}/mpc ${WRKDIR}/${BINUTILS_DISTNAME}/
	${MV} ${WRKSRC}/mpfr ${WRKDIR}/${BINUTILS_DISTNAME}/
	@${STEP_MSG} Building in-place binutils
	${RUN}cd ${WRKDIR}/${BINUTILS_DISTNAME} && \
	    ${PKGSRC_SETENV} ${CONFIGURE_ENV} \
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} \
		${CONFIGURE_SCRIPT} --with-libpath=${LIB_PATH:Q} --program-prefix=g --prefix=/. --enable-plugins && \
	    ${PKGSRC_SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} -f Makefile all && \
	    ${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} DESTDIR=${BUILDLINK_DIR} -f Makefile install && \
	    ${CP} ${WRKDIR}/${BINUTILS_DISTNAME}/intl/libintl.a ${BUILDLINK_DIR}/lib && \
	    ${CP} ${WRKDIR}/${BINUTILS_DISTNAME}/libiberty/libiberty.a ${BUILDLINK_DIR}/lib

BUILD_DIRS=	tools/gnatcov
BUILD_TARGET=	all
MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
MAKE_FLAGS+=	BUILD_MODE=prod C_SUPPORT=False
#MAKE_FLAGS+=	GNAT_SRC_DIR=${WRKDIR}/${GCC_DISTNAME}/gcc/ada

INSTALL_TARGET=	install install-adapters

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin lib libexec share \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../devel/ada-gnat_util14/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-libgpr2-25/buildlink3.mk"
.include "../../devel/ada-libadalang-25/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
