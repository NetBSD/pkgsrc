# $NetBSD: Makefile,v 1.39 2004/03/22 00:15:07 dmcmahill Exp $
#

DISTNAME=	verilog-${SNAPDATE}
PKGNAME=	verilog-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (development snapshot version)

PKG_INSTALLATION_TYPES=        overwrite pkgviews

CONFLICTS+=	verilog-[0-9]*

USE_BUILDLINK3=	yes
BUILD_DEPENDS+= bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+= gperf>=2.7.2:../../devel/gperf

SNAPDATE=	20040220
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	lex make
CONFIGURE_ARGS+=	--without-ipal
YACC=		${LOCALBASE}/bin/bison
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
