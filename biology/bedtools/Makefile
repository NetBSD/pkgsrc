# $NetBSD: Makefile,v 1.1 2021/01/22 17:07:50 bacon Exp $

DISTNAME=	bedtools-2.29.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=arq5x/}
GITHUB_PROJECT=	bedtools2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://bedtools.readthedocs.io/en/latest/
COMMENT=	Swiss army knife for genome arithmetic
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
REPLACE_SH+=	scripts/vcfsort.sh
REPLACE_PYTHON=	scripts/makeBashScripts.py

SUBST_CLASSES+=		pybin
SUBST_STAGE.pybin=	pre-configure
SUBST_SED.pybin=	-e 's|python|${PYTHONBIN}|g'
SUBST_FILES.pybin=	Makefile

# Avoid conflict with C++20 <version> by adding .txt suffix
post-extract:
	${MV} ${WRKSRC}/src/utils/gzstream/version \
		${WRKSRC}/src/utils/gzstream/version.txt

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
