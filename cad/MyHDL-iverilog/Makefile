# $NetBSD: Makefile,v 1.7 2012/10/08 13:25:10 asau Exp $
#

DISTNAME=	myhdl-0.7
PKGNAME=	MyHDL-iverilog-0.7
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Icarus Verilog cosimulation support for py-MyHDL

BUILD_DIRS+=	cosimulation/icarus

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/ivl
	${INSTALL_DATA} ${WRKSRC}/cosimulation/icarus/myhdl.vpi \
		${DESTDIR}${PREFIX}/lib/ivl

# XXX would require Python dependency
#do-test:
#	(cd ${WRKSRC}/cosimulation/icarus/test && ${PYTHONBIN} test_all.py)

.include "../../cad/verilog/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
