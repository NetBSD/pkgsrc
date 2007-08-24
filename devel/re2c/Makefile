# $NetBSD: Makefile,v 1.10 2007/08/24 14:56:13 heinz Exp $

DISTNAME=	re2c-0.12.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=re2c/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://re2c.org/
COMMENT=	Deterministic Finite State Automaton generator

PKG_DESTDIR_SUPPORT=user-destdir

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

REPLACE_SH+=	run_tests.sh.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
