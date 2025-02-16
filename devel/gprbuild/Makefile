# $NetBSD: Makefile,v 1.6 2025/02/16 10:11:48 wiz Exp $

DISTNAME=	gprbuild-25.0.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gprbuild
COMMENT=	Build system for Ada
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c ada

GITHUB_SUBMODULES+=	AdaCore	xmlada	${GITHUB_TAG}	deps/xmlada
GITHUB_SUBMODULES+=	AdaCore	gprconfig_kb	${GITHUB_TAG}	deps/gprconfig_kb

USE_TOOLS+=	gmake

MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

HAS_CONFIGURE=	yes

GCC_REQD+=	13

OBJDIR=		${WRKDIR}/build
BOOTSTRAPDIR=	${WRKDIR}/bootstrap

GPR_PROJECT_PATH=	${WRKDIR}/.buildlink/share/gpr

# environment for bootstrap build
PREBUILD_ENV=	${CONFIGURE_ENV}
PREBUILD_ENV+=	CC=${CC}
PREBUILD_ENV+=	CFLAGS=${CFLAGS:M:Q}
PREBUILD_ENV+=	GNATMAKE=${GMKPATH}

CONFIGURE_DIRS=		${OBJDIR}
CONFIG_SHELL=		${MAKE_PROGRAM} -f
CONFIGURE_SCRIPT=	${WRKSRC}/Makefile
CONFIGURE_ARGS=		setup
CONFIGURE_ARGS+=	prefix=${DESTDIR}${PREFIX} SOURCE_DIR=${WRKSRC} ENABLE_SHARED=yes

BUILD_DIRS=		${OBJDIR}
MAKE_FILE=		${WRKSRC}/Makefile
BUILD_MAKE_FLAGS=	GPRBUILD_OPTIONS='-aP ${GPR_PROJECT_PATH}'

INSTALL_DIRS=		${OBJDIR}
INSTALL_MAKE_FLAGS+=	GPRINSTALL_OPTIONS='-aP ${GPR_PROJECT_PATH}'

SUBST_CLASSES+=			fixver
SUBST_STAGE.fixver=		pre-configure
SUBST_FILES.fixver=		deps/xmlada/configure
SUBST_MESSAGE.fixver=		Fix version in configure
SUBST_SED.fixver=		-e 's,18.0w,25.0w,g'

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin libexec share \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.prefs.mk"

post-extract:
	${RUN} ${MKDIR} ${OBJDIR}

pre-configure:
# Bootstrap build. Moved here because configure script of gprbuild uses gprbuild itself.
	${RUN} ${MKDIR} ${BOOTSTRAPDIR}
	${RUN} cd ${BOOTSTRAPDIR} \
	&& set -x ; env ${PREBUILD_ENV} \
	${SHELL} ${WRKSRC}/bootstrap.sh \
	    --prefix=${WRKDIR}/.buildlink \
	    --srcdir=${WRKSRC} \
	    --with-xmlada=${WRKSRC}/deps/xmlada \
	    --with-kb=${WRKSRC}/deps/gprconfig_kb

pre-build:
# Xmlada's configure uses gprbuild. So we configure it here.
	${RUN} cd ${WRKSRC}/deps/xmlada \
	&& set -x ; env ${CONFIGURE_ENV} \
	./configure \
	    --prefix=${WRKDIR}/.buildlink
# Build xmlada with bootstrapped gprbuild. It then will be used in normal build.
	${RUN} cd ${WRKSRC}/deps/xmlada \
	&& set -x ; env ${MAKE_ENV} \
	${MAKE_PROGRAM} static-pic install-static-pic

.include "../../mk/bsd.pkg.mk"
