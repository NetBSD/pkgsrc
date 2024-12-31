# $NetBSD: Makefile,v 1.32 2024/12/31 14:56:27 wiz Exp $

DISTNAME=	re2c-4.0.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=skvadrik/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://re2c.org/
COMMENT=	Deterministic Finite State Automaton generator
LICENSE=	public-domain

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison
# needs 'make install'
TEST_TARGET=		check
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/bsd.fast.prefs.mk"

.if ${PKGMANDIR} != "share/man"
SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man/man1,${PKGMANDIR}/man1,"
SUBST_FILES.man+=	CMakeLists.txt
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing man page path.
.endif

.include "../../lang/python/tool.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
