# $NetBSD: Makefile,v 1.7 2004/03/12 22:35:31 dmcmahill Exp $
#

DISTNAME=	covered-${SNAPDATE}
PKGNAME=	covered-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://covered.sourceforge.net/
COMMENT=	Verilog code coverage analyzer (development snapshot)

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=	yes
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	gperf>=2.7.2:../../devel/gperf
DEPENDS+=	verilog{,-current}-[0-9]*:../../cad/verilog

CONFLICTS+=     covered-[0-9]*

SNAPDATE=	20040211
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

.include "../../mk/bsd.pkg.mk"
