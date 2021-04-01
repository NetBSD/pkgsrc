# $NetBSD: Makefile,v 1.25 2021/04/01 16:46:39 wiz Exp $

DISTNAME=	re2c-2.1.1
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
TEST_TARGET=		check

# TODO: works only with Bash
CHECK_PORTABILITY_SKIP=	run_tests.sh.in
REPLACE_SH+=		run_tests.sh.in

.include "../../mk/bsd.pkg.mk"
