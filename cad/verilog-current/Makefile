# $NetBSD: Makefile,v 1.45 2004/12/01 12:36:21 dmcmahill Exp $
#

DISTNAME=	verilog-${SNAPDATE}
PKGNAME=	verilog-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/pre-0.8/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (development snapshot version)

PKG_INSTALLATION_TYPES=        overwrite pkgviews

CONFLICTS+=	verilog-[0-9]*

USE_BUILDLINK3=	yes
BUILD_DEPENDS+= bison-[0-9]*:../../devel/bison

SNAPDATE=	20041004
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	lex make
CONFIGURE_ARGS+=	--without-ipal
YACC=		${LOCALBASE}/bin/bison
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
