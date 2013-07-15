# $NetBSD: Makefile,v 1.59 2013/07/15 02:02:18 ryoon Exp $
#

DISTNAME=	verilog-${SNAPDATE}
PKGNAME=	verilog-current-${SNAPDATE}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (development snapshot version)
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	verilog-[0-9]*

GCC_REQD+=	3.0
USE_LANGUAGES=	c c++

SNAPDATE=		20090923
GNU_CONFIGURE=		yes
USE_TOOLS+=		bison gmake lex
CONFIGURE_ARGS+=	--without-ipal
TEST_DIRS=		.
TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
