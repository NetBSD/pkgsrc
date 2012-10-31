# $NetBSD: Makefile,v 1.13 2012/10/31 11:19:38 asau Exp $

DISTNAME=	re2c-0.13.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=re2c/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://re2c.org/
COMMENT=	Deterministic Finite State Automaton generator
LICENSE=	public-domain

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CHECK_PORTABILITY_SKIP=	run_tests.sh.in
REPLACE_SH+=		run_tests.sh.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
