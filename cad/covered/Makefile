# $NetBSD: Makefile,v 1.10 2006/02/05 23:08:20 joerg Exp $
#

DISTNAME=	covered-0.3
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://covered.sourceforge.net/
COMMENT=	Verilog code coverage analyzer (stable release version)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	verilog{,-current}-[0-9]*:../../cad/verilog

CONFLICTS+=	covered-current-[0-9]*

REPLACE_PERL=	diags/verilog/check_test
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl:run
TEST_DIRS=	${WRKSRC}/diags/regress
TEST_TARGET=	iverilog

post-patch:
	${CHMOD} 755 ${WRKSRC}/missing

pre-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1

.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
