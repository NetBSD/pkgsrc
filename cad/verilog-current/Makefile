# $NetBSD: Makefile,v 1.12 2001/02/16 13:46:30 wiz Exp $
#

DISTNAME=	verilog-20010113
PKGNAME=	verilog-current-20010113
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (development snapshot version)

BUILD_DEPENDS+=	bison:../../devel/bison
BUILD_DEPENDS+=	gperf:../../devel/gperf
DEPENDS+=	ipal-current>=20001210:../../cad/ipal-current

CONFLICTS+=	verilog

GNU_CONFIGURE=	yes
USE_GMAKE=      yes
CPPFLAGS+=      -I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS+="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
