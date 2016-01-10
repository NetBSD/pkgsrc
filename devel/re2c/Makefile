# $NetBSD: Makefile,v 1.16 2016/01/10 10:01:02 adam Exp $

DISTNAME=	re2c-0.15.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=re2c/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://re2c.org/
COMMENT=	Deterministic Finite State Automaton generator
LICENSE=	public-domain

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CHECK_PORTABILITY_SKIP=	run_tests.sh.in
REPLACE_SH+=		run_tests.sh.in

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
