# $NetBSD: Makefile,v 1.1.1.1 2002/12/08 04:21:43 dmcmahill Exp $
#

DISTNAME=	covered-${SNAPDATE}
PKGNAME=	covered-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://covered.sourceforge.net
COMMENT=	Verilog code coverage analyzer

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
DEPENDS+=	verilog{,-current}-[0-9]*:../../cad/verilog

SNAPDATE=	20021127
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
TEST_DIRS=	${WRKSRC}/diags/regress
TEST_TARGET=	#defined

post-patch:
	${CHMOD} 755 ${WRKSRC}/missing

.include "../../mk/bsd.pkg.mk"
