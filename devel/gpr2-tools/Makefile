# $NetBSD: Makefile,v 1.2 2025/10/12 07:21:14 dkazankov Exp $

DISTNAME=	gpr2-${GITHUB_TAG}
PKGNAME=	gpr2-tools-${GITHUB_TAG}.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gpr
GITHUB_TAG=	25.2

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

DEPENDS=	pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		fixparam
SUBST_STAGE.fixparam=	pre-configure
SUBST_FILES.fixparam=	Makefile
SUBST_MESSAGE.fixparam=	Fix realpath parameter
SUBST_SED.fixparam=	-e 's, --relative-to=. , ,g'
.endif

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
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
