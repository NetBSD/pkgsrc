# $NetBSD: Makefile,v 1.1 2024/03/12 17:50:12 wiz Exp $

.include "version.mk"

DISTNAME=	gprbuild-${GPRBUILD_VERSION}
CATEGORIES=	devel
MAINTAINER=	pkgsrc-users@NetBSD.org
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/AdaCore/gprbuild
COMMENT=	GPRbuild build system for Ada
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c ada

GITHUB_SUBMODULES+=	AdaCore	xmlada	${GITHUB_TAG}	deps/xmlada
GITHUB_SUBMODULES+=	AdaCore	gprconfig_kb	${GITHUB_TAG}	deps/gprconfig_kb

USE_TOOLS+=	gmake

HAS_CONFIGURE=	yes

GCC_REQD+=	13

OBJDIR=		${WRKDIR}/build
BOOTSTRAPDIR=	${WRKDIR}/bootstrap
CGPRDIR=	${WRKDIR}

# environment for bootstrap build
PREBUILD_ENV=	${CONFIGURE_ENV}
PREBUILD_ENV+=	CC=${CC}
PREBUILD_ENV+=	CFLAGS=${CFLAGS:M:Q}
PREBUILD_ENV+=	GNATMAKE=${GMKPATH}

CONFIGURE_DIRS=		${OBJDIR}
CONFIG_SHELL=		${MAKE_PROGRAM} -f
CONFIGURE_SCRIPT=	${WRKSRC}/Makefile
CONFIGURE_ARGS=		setup
CONFIGURE_ARGS+=	prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	SOURCE_DIR=${WRKSRC}

BUILD_DIRS=		${OBJDIR}
MAKE_FILE=		${WRKSRC}/Makefile
BUILD_MAKE_FLAGS=	GPRBUILD_OPTIONS='--config=${CGPRDIR}/buildlink.cgpr -aP ${WRKDIR}/.buildlink/share/gpr'

INSTALL_DIRS=		${OBJDIR}
INSTALL_MAKE_FLAGS=	GPRBUILD_OPTIONS='--config=${CGPRDIR}/buildlink.cgpr -aP ${WRKDIR}/.buildlink/share/gpr'
INSTALL_MAKE_FLAGS+=	GPRINSTALL_OPTIONS='--config=${CGPRDIR}/buildlink.cgpr -aP ${WRKDIR}/.buildlink/share/gpr'

SUBST_CLASSES+=			buildlink
SUBST_STAGE.buildlink=		post-configure
SUBST_FILES.buildlink=		../buildlink.cgpr
SUBST_MESSAGE.buildlink=	Set work directory path in config project
SUBST_VARS.buildlink=		WRKDIR

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin libexec share \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.prefs.mk"

pre-configure:
	${RUN} ${CP} ${PKGDIR}/files/buildlink.cgpr ${CGPRDIR}/
	${RUN} ${MKDIR} ${OBJDIR}

post-configure:
	${RUN} cd ${WRKSRC}/deps/xmlada \
	&& set -x ; env ${CONFIGURE_ENV} \
	./configure \
	    --prefix=${WRKDIR}/.buildlink

pre-build:
# Bootstrap build
	${RUN} ${MKDIR} ${BOOTSTRAPDIR}
	${RUN} cd ${BOOTSTRAPDIR} \
	&& set -x ; env ${PREBUILD_ENV} \
	${SHELL} ${WRKSRC}/bootstrap.sh \
	    --prefix=${WRKDIR}/.buildlink \
	    --srcdir=${WRKSRC} \
	    --with-xmlada=${WRKSRC}/deps/xmlada \
	    --with-kb=${WRKSRC}/deps/gprconfig_kb
# Build xmlada with bootstrapped gprbuild. It then will be used in normal build.
	${RUN} cd ${WRKSRC}/deps/xmlada \
	&& set -x ; env ${MAKE_ENV} \
	${MAKE_PROGRAM} all install GPROPTS='--config=${CGPRDIR}/buildlink.cgpr'

.include "../../mk/bsd.pkg.mk"
