# $NetBSD: Makefile,v 1.1 2025/07/28 09:07:49 dkazankov Exp $

DISTNAME=	libgpr2-${PKGVERSION_NOREV}
PKGNAME=	gpr2-tools-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gpr
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gpr
COMMENT=	Parser for GPR Project files - tools package
LICENSE=	apache-2.0 AND gnu-gpl-v3

GITHUB_SUBMODULES+=	AdaCore	gprconfig_kb	${GITHUB_TAG}	gprconfig_kb

USE_TOOLS+=	gmake realpath

USE_LANGUAGES=	c ada

GCC_REQD+=	14

HAS_CONFIGURE=	yes

USE_GCC_RUNTIME=	yes

CHECK_PIE_SKIP+=	bin/*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		fixparam
SUBST_STAGE.fixparam=	pre-configure
SUBST_FILES.fixparam=	Makefile
SUBST_MESSAGE.fixparam=	Fix realpath parameter
SUBST_SED.fixparam=	-e 's, --relative-to=. , ,g'
.endif

#SUBST_CLASSES+=		gprconfig
#SUBST_MESSAGE.gprconfig=	Replace gprconfig in ${SUBST_FILES.gprconfig}
#SUBST_STAGE.gprconfig=	pre-configure
#SUBST_FILES.gprconfig=	tools/src/gprconfig.adb
#SUBST_SED.gprconfig=	-e "s,\"gprconfig\",\"gpr2config\","

#SUBST_CLASSES+=		gprinstall
#SUBST_MESSAGE.gprinstall=	Replace gprinstall in ${SUBST_FILES.gprinstall}
#SUBST_STAGE.gprinstall=	pre-configure
#SUBST_FILES.gprinstall=	tools/src/gprinstall-main.adb
#SUBST_SED.gprinstall=	-e "s,\"gprinstall\",\"gpr2install\","

#SUBST_CLASSES+=		gprls
#SUBST_MESSAGE.gprls=	Replace gprls in ${SUBST_FILES.gprls}
#SUBST_STAGE.gprls=	pre-configure
#SUBST_FILES.gprls=	tools/src/gprls-main.adb
#SUBST_SED.gprls=	-e "s,\"gprls\",\"gpr2ls\","

CONFIG_SHELL=		${MAKE_PROGRAM} -f
CONFIGURE_SCRIPT=	${WRKSRC}/Makefile
CONFIGURE_ARGS=		setup
CONFIGURE_ARGS+=	prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	GPR2_BUILD=release
CONFIGURE_ARGS+=	GPR2KBDIR=gprconfig_kb/db

BUILD_TARGET=		build-tools
INSTALL_TARGET=		install-tools

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin share \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../math/ada-adasat-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"

.include "../../devel/gmp/buildlink3.mk"
USE_GNU_ICONV=		yes
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
