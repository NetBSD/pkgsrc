# $NetBSD: Makefile,v 1.3 2003/12/09 01:20:36 dmcmahill Exp $
#

DISTNAME=	covered-0.2.2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://covered.sourceforge.net/
COMMENT=	Verilog code coverage analyzer (stable release version)

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
DEPENDS+=	verilog{,-current}-[0-9]*:../../cad/verilog

CONFLICTS+=	covered-current-[0-9]*

USE_PERL5=	YES
REPLACE_PERL=	diags/verilog/check_test
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
TEST_DIRS=	${WRKSRC}/diags/regress
TEST_TARGET=	iverilog

post-patch:
	${CHMOD} 755 ${WRKSRC}/missing

.include "../../mk/bsd.pkg.mk"
