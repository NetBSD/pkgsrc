# $NetBSD: Makefile,v 1.19 2004/10/14 22:29:04 dmcmahill Exp $
#

DISTNAME=	verilog-0.8
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.8/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (stable release version)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

CONFLICTS+=	verilog-current-[0-9]*

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	lex make
CONFIGURE_ARGS+=	--without-ipal
YACC=			${LOCALBASE}/bin/bison
TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
