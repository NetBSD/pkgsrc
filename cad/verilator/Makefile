# $NetBSD: Makefile,v 1.12 2025/12/28 14:47:42 wiz Exp $

DISTNAME=	verilator-5.042
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=verilator/}
GITHUB_PROJECT=	verilator
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.veripool.org/verilator/
COMMENT=	Verilog HDL simulator
LICENSE=	gnu-lgpl-v3 OR artistic-2.0

TOOL_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

GNU_CONFIGURE=	yes
FLEX_REQD+=	2.6.4
USE_TOOLS+=	autoconf automake autoreconf bison flex gmake:run perl
USE_LANGUAGES=	c c++

TOOLS_PLATFORM.flex=	# Use flex from pkgsrc

REPLACE_PERL+=	bin/*
REPLACE_PERL+=	test_regress/*.pl
REPLACE_PERL+=	test_regress/t/*.pl

REPLACE_PYTHON+=	bin/*

# Do not pass "bison -y" to bisonpre Python script.
CONFIGURE_ENV+=		ac_cv_prog_YACC=${TOOLS_CMD.bison:Q}
# Find PYTHONBIN at runtime
CONFIGURE_ENV+=		PYTHON3=${PYTHONBIN}

# for long tests
TEST_DEPENDS+=		p5-Unix-Processors-[0-9]*:../../sysutils/p5-Unix-Processors
CONFIGURE_ARGS+=	--enable-longtests
TEST_TARGET=		test

PKGCONFIG_OVERRIDE+=	verilator.pc.in

pre-configure:
	# Do not regenerate src/config_package.h.
	# Regenerated one is incorrect.
	set -e; cd ${WRKSRC} && AUTOHEADER=true autoreconf -fi

.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
