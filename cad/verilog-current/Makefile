# $NetBSD: Makefile,v 1.21 2001/09/27 23:17:47 jlam Exp $
#

DISTNAME=	verilog-20010630
PKGNAME=	verilog-current-20010630
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (development snapshot version)

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
DEPENDS+=	ipal-current>=20001210:../../cad/ipal-current

CONFLICTS+=	verilog-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=      yes
CPPFLAGS+=      -I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS+="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
