# $NetBSD: Makefile,v 1.23 2001/12/15 18:43:37 dmcmahill Exp $
#

DISTNAME=	verilog-20011209
PKGNAME=	verilog-current-20011209
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (development snapshot version)

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
# turn this back on when ipal comes along a little further
#DEPENDS+=	ipal-current>=20001210:../../cad/ipal-current

CONFLICTS+=	verilog-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=      yes
#
# for ipal.h
#CPPFLAGS+=      -I${LOCALBASE}/include
#CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS+="${LDFLAGS}"
CONFIGURE_ARGS+=	--without-ipal

.include "../../mk/bsd.pkg.mk"
