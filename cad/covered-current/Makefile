# $NetBSD: Makefile,v 1.5 2003/12/30 17:21:55 cjep Exp $
#

DISTNAME=	covered-${SNAPDATE}
PKGNAME=	covered-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://covered.sourceforge.net/
COMMENT=	Verilog code coverage analyzer

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	gperf-2.7.2:../../devel/gperf
DEPENDS+=	verilog{,-current}-[0-9]*:../../cad/verilog

CONFLICTS+=     covered-[0-9]*

SNAPDATE=	20021214
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
TEST_DIRS=	${WRKSRC}/diags/regress
TEST_TARGET=	#defined

post-patch:
	${CHMOD} 755 ${WRKSRC}/missing

.include "../../mk/bsd.pkg.mk"
