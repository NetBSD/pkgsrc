# $NetBSD: Makefile,v 1.8 2026/06/07 03:54:41 dkazankov Exp $

DISTNAME=	${PKGNAME}
PKGNAME=	gprbuild-26.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gprbuild
COMMENT=	Build system for Ada
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c ada

GITHUB_SUBMODULES+=	AdaCore	gprconfig_kb	${GITHUB_TAG}	deps/gprconfig_kb

USE_TOOLS+=	gmake

MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

HAS_CONFIGURE=	yes

DEPENDS=	pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	15

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Replace version,date and type in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	gpr/src/gpr-version.ads
SUBST_SED.version=	-e "s,18.0w,26.0,"
SUBST_SED.version+=	-e "s,19940713,20251128,"
SUBST_SED.version+=	-e "s,\"2016\",\"2025\","
SUBST_SED.version+=	-e "s,= Gnatpro;,= FSF;,"

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=			getrusage
SUBST_MESSAGE.getrusage=	Replace getrusage with __netbsd_getrusage in ${SUBST_FILES.getrusage}
SUBST_STAGE.getrusage=		post-extract
SUBST_FILES.getrusage=		gpr/src/gpr-util-put_resource_usage__unix.adb
SUBST_SED.getrusage=		-e "s,with Import\, Convention => C;,with Import\, Convention => C\, External_Name => \"__netbsd_getrusage\";,"
.endif

OBJDIR=		${WRKDIR}/build
BOOTSTRAPDIR=	${WRKDIR}/bootstrap

GPR_PROJECT_PATH=	${WRKDIR}/.buildlink/share/gpr
GPRBUILD_OPTIONS=	-aP ${GPR_PROJECT_PATH:Q}
GPRINSTALL_OPTIONS=	-aP ${GPR_PROJECT_PATH:Q}

pre-configure:
	${MV} ${WRKSRC}/xmlada ${WRKSRC}/deps/
# Bootstrap build. Moved here because configure script of gprbuild uses gprbuild itself.
	${RUN} ${MKDIR} ${OBJDIR} && \
	${MKDIR} ${BOOTSTRAPDIR} && \
	cd ${BOOTSTRAPDIR} && \
	${PKGSRC_SETENV} ${PREBUILD_ENV} \
	${SH} ${WRKSRC}/bootstrap.sh \
	    --prefix=${WRKDIR}/.buildlink \
	    --srcdir=${WRKSRC} \
	    --with-xmlada=${WRKSRC}/deps/xmlada \
	    --with-kb=${WRKSRC}/deps/gprconfig_kb

CONFIGURE_DIRS=		${OBJDIR}
CONFIG_SHELL=		${MAKE_PROGRAM} -f
CONFIGURE_SCRIPT=	${WRKSRC}/Makefile
CONFIGURE_ARGS=		setup
CONFIGURE_ARGS+=	prefix=${DESTDIR}${PREFIX} SOURCE_DIR=${WRKSRC} ENABLE_SHARED=no

# environment for bootstrap build
PREBUILD_ENV=	${CONFIGURE_ENV}
PREBUILD_ENV+=	CC=${CC:Q}
PREBUILD_ENV+=	CFLAGS=${CFLAGS:M:Q}
PREBUILD_ENV+=	GNATMAKE=${GMKPATH:Q}

pre-build:
# Xmlada's configure uses gprbuild. So we configure it here.
	${RUN}cd ${WRKSRC}/deps/xmlada && \
	${PKGSRC_SETENV} ${CONFIGURE_ENV} \
	./configure \
	    --prefix=${WRKDIR}/.buildlink --disable-shared
# Build xmlada with bootstrapped gprbuild. It then will be used in normal build.
	${RUN}cd ${WRKSRC}/deps/xmlada && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} static install-static

BUILD_DIRS=		${OBJDIR}
MAKE_FILE=		${WRKSRC}/Makefile
BUILD_MAKE_FLAGS=	GPRBUILD_OPTIONS=${GPRBUILD_OPTIONS:Q}

INSTALL_DIRS=		${OBJDIR}
INSTALL_MAKE_FLAGS+=	GPRINSTALL_OPTIONS=${GPRINSTALL_OPTIONS:Q}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin libexec share \( -type f -or -type l \) -print | ${SORT};

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/gprconfig/linker.xml.orig
	${RUN}cd ${DESTDIR}${PREFIX}/bin && \
	    ${MV} gprbuild gpr1build && \
	    ${MV} gprconfig gpr1config && \
	    ${MV} gprclean gpr1clean

.include "../../textproc/ada-xmlada26/inplace.mk"

.include "../../mk/bsd.pkg.mk"
