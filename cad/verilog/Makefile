# $NetBSD: Makefile,v 1.9 2001/06/11 06:34:20 jlam Exp $
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

CONFLICTS+=	verilog-current-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
# to find ipal.h:
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
