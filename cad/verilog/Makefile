# $NetBSD: Makefile,v 1.10 2001/08/04 01:20:43 dmcmahill Exp $
#

DISTNAME=	verilog-0.5
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.5/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (stable release version)

BUILD_DEPENDS+=	bison-*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
#
# turn this back on when ipal comes along a little further
#DEPENDS+=	ipal-current>=20001210:../../cad/ipal-current

CONFLICTS+=	verilog-current-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
# to find ipal.h:
#CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--without-ipal

.include "../../mk/bsd.pkg.mk"
