# $NetBSD: Makefile,v 1.7 2001/03/27 03:19:47 hubertf Exp $
#

DISTNAME=	verilog-0.4
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.4/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (stable release version)

BUILD_DEPENDS+=	bison-*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
DEPENDS+=	ipal-current>=20001210:../../cad/ipal-current

CONFLICTS+=	verilog-current

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
# to find ipal.h:
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS+="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
