# $NetBSD: Makefile,v 1.6 2001/02/16 13:46:29 wiz Exp $
#

DISTNAME=	verilog-0.4
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.4/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (stable release version)

BUILD_DEPENDS+=	bison:../../devel/bison
BUILD_DEPENDS+=	gperf:../../devel/gperf
DEPENDS+=	ipal-current>=20001210:../../cad/ipal-current

CONFLICTS+=	verilog-current

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
# to find ipal.h:
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS+="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
