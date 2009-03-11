# $NetBSD: Makefile,v 1.31 2009/03/11 02:08:08 dmcmahill Exp $
#

DISTNAME=	verilog-0.8.7
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.8/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (stable release version)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	verilog-current-[0-9]*

USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison lex
CONFIGURE_ARGS+=	--without-ipal
TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
