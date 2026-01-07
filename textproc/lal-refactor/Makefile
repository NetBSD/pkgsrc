# $NetBSD: Makefile,v 1.3 2026/01/07 23:33:46 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	lal-refactor
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/lal-refactor
COMMENT=	Collection of source code refactoring tools for the Ada
LICENSE=	apache-2.0

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

MAKE_FLAGS+=		BUILD_MODE=prod
BUILD_TARGET=		bin

INSTALL_TARGET=		install-bin

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin \( -type f -or -type l \) -print | ${SORT};

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
.include "../../textproc/ada-templates-parser-25/buildlink3.mk"
.include "../../devel/ada-langkit-support-25/buildlink3.mk"
.include "../../devel/ada-libadalang-25/buildlink3.mk"
.include "../../devel/ada-liblal-tools-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
