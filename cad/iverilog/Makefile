# $NetBSD: Makefile,v 1.4 2024/09/21 21:04:39 mef Exp $

DISTNAME=	verilog-12.0
# There is confision in naming of this software, use iverilog as it's saner
PKGNAME=	i${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=steveicarus/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./_/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	https://steveicarus.github.io/iverilog/
COMMENT=	Verilog simulation and synthesis tool (stable release version)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison lex autoconf
TEST_TARGET=		check

INSTALLATION_DIRS+=	share/doc/ivl

pre-configure:
	(cd ${WRKSRC}; autoconf)
# Additional files
post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} \
		QUICK_START.txt \
		README.md      \
	${DESTDIR}${PREFIX}/share/doc/ivl

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
