# $NetBSD: Makefile,v 1.6 2004/11/27 15:04:02 dmcmahill Exp $
#

DISTNAME=	covered-0.3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://covered.sourceforge.net/
COMMENT=	Verilog code coverage analyzer (stable release version)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	verilog{,-current}-[0-9]*:../../cad/verilog

CONFLICTS+=	covered-current-[0-9]*

USE_PERL5=	YES
REPLACE_PERL=	diags/verilog/check_test
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
TEST_DIRS=	${WRKSRC}/diags/regress
TEST_TARGET=	iverilog

post-patch:
	${CHMOD} 755 ${WRKSRC}/missing

pre-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1

.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
