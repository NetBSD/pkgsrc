# $NetBSD: Makefile,v 1.3 2026/01/07 23:33:46 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatdoc
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatdoc
COMMENT=	GNAT Documentation Generation Tool
LICENSE=	gnu-gpl-v3 AND apache-2.0

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Replace version and date in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	source/gnatdoc/gnatdoc-version.ads
SUBST_SED.version=	-e "s,%VERSION% (%DATE%),${GITHUB_TAG} (20241217),"

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin include share \( -type f -or -type l \) -print | ${SORT};

CHECK_PIE_SKIP+=	bin/*

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../math/ada-adasat-25/buildlink3.mk"
.include "../../devel/ada-libgpr2-25/buildlink3.mk"
.include "../../textproc/ada-vss-25/buildlink3.mk"
.include "../../textproc/ada-prettier-ada-25/buildlink3.mk"
.include "../../devel/ada-langkit-support-25/buildlink3.mk"
.include "../../devel/ada-libadalang-25/buildlink3.mk"
.include "../../textproc/ada-markdown-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
