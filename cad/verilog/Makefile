# $NetBSD: Makefile,v 1.13 2002/12/15 01:57:12 dmcmahill Exp $
#

DISTNAME=	verilog-0.7
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.7/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (stable release version)

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
# turn this back on when ipal comes along a little further
#DEPENDS+=	ipal-current>=20001210:../../cad/ipal-current

CONFLICTS+=	verilog-current-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=      yes
#
# for ipal.h
#CPPFLAGS+=      -I${LOCALBASE}/include
#CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS+="${LDFLAGS}"
CONFIGURE_ARGS+=	--without-ipal
YACC=			${LOCALBASE}/bin/bison
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
