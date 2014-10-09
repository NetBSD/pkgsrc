# $NetBSD: Makefile,v 1.61 2014/10/09 14:06:01 wiz Exp $
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

# In driver:
# mkdir: dep: Not a directory
# Makefile:76: recipe for target 'dep' failed
MAKE_JOBS_SAFE=	no

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
