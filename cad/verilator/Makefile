# $NetBSD: Makefile,v 1.10 2022/07/25 11:12:20 wiz Exp $

DISTNAME=	verilator-4.100
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	https://www.veripool.org/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.veripool.org/wiki/verilator
COMMENT=	Verilog HDL simulator
LICENSE=	gnu-lgpl-v3 OR artistic-2.0

GNU_CONFIGURE=	yes
FLEX_REQD=	2.6.4
USE_TOOLS+=	bison flex gmake perl
USE_LANGUAGES=	c c++

TOOLS_PLATFORM.flex=	# Use flex from pkgsrc

REPLACE_PERL+=	bin/*
REPLACE_PERL+=	test_regress/*.pl
REPLACE_PERL+=	test_regress/t/*.pl

CONFIGURE_ENV+=		ac_cv_path_YACC=bison

# for long tests
TEST_DEPENDS+=		p5-Unix-Processors-[0-9]*:../../sysutils/p5-Unix-Processors
CONFIGURE_ARGS+=	--enable-longtests
TEST_TARGET=		test

PKGCONFIG_OVERRIDE+=	verilator.pc.in

.include "../../mk/bsd.pkg.mk"
