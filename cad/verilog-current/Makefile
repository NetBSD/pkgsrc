# $NetBSD: Makefile,v 1.19 2001/06/11 06:34:20 jlam Exp $
#

DISTNAME=	verilog-20010520
PKGNAME=	verilog-current-20010520
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (development snapshot version)

BUILD_DEPENDS+=	bison-*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
DEPENDS+=	ipal-current>=20001210:../../cad/ipal-current

CONFLICTS+=	verilog-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=      yes
CPPFLAGS+=      -I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
