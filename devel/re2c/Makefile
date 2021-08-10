# $NetBSD: Makefile,v 1.26 2021/08/10 19:34:17 wiz Exp $

DISTNAME=	re2c-2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=skvadrik/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://re2c.org/
COMMENT=	Deterministic Finite State Automaton generator
LICENSE=	public-domain

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison gmake
GNU_CONFIGURE=		yes
# as of 2.2:
# FAIL: run_tests.py
TEST_TARGET=		check
PYTHON_FOR_BUILD_ONLY=	test

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
