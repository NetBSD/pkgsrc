# $NetBSD: Makefile,v 1.3 2022/06/30 11:18:04 nia Exp $

DISTNAME=	bedtools-2.30.0
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=arq5x/}
GITHUB_PROJECT=	bedtools2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://bedtools.readthedocs.io/en/latest/
COMMENT=	Swiss army knife for genome arithmetic
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:test gmake
REPLACE_SH+=	scripts/vcfsort.sh
REPLACE_PYTHON=	scripts/makeBashScripts.py

SUBST_CLASSES+=		pybin
SUBST_STAGE.pybin=	pre-configure
SUBST_SED.pybin=	-e 's|python|${PYTHONBIN}|g'
SUBST_FILES.pybin=	Makefile

do-test:
	cd ${WRKSRC}/test && bash test.sh

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
