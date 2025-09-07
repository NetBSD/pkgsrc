# $NetBSD: Makefile,v 1.1 2025/09/07 08:08:50 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gnatdoc
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gnatdoc
COMMENT=	GNAT Documentation Generation Tool
LICENSE=	gnu-gpl-v3 AND apache-2.0

USE_LANGUAGES=	ada

USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

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
