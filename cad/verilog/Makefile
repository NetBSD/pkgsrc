# $NetBSD: Makefile,v 1.17 2004/03/12 02:51:53 dmcmahill Exp $
#

DISTNAME=	verilog-0.7
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.7/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (stable release version)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	gperf>=2.7.2:../../devel/gperf

CONFLICTS+=	verilog-current-[0-9]*

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
CONFIGURE_ARGS+=	--without-ipal
YACC=			${LOCALBASE}/bin/bison
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
