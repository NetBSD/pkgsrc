# $NetBSD: Makefile,v 1.8 2015/01/04 02:45:50 mef Exp $
#

DISTNAME=	myhdl-0.8.1
PKGNAME=	MyHDL-iverilog-0.7
PKGNAME=	${DISTNAME:C/myhdl/MyHDL-iverilog/}
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Icarus Verilog cosimulation support for py-MyHDL
LICENSE=	gnu-gpl-v2

BUILD_DIRS+=	cosimulation/icarus
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/cosimulation/icarus/myhdl.vpi \
		${DESTDIR}${PREFIX}/lib/ivl

# XXX would require Python dependency
#do-test:
#	(cd ${WRKSRC}/cosimulation/icarus/test && ${PYTHONBIN} test_all.py)

.include "../../cad/verilog/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
