# $NetBSD: Makefile,v 1.7 2012/10/08 13:25:10 asau Exp $
#

DISTNAME=	myhdl-0.7
PKGNAME=	MyHDL-gplcver-0.7
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	GPL Cver cosimulation support for py-MyHDL

BUILD_DIRS+=	cosimulation/cver
MAKE_FILE=	makefile.lnx

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/gplcver
	${INSTALL_DATA} ${WRKSRC}/cosimulation/cver/myhdl_vpi.so \
		${DESTDIR}${PREFIX}/lib/gplcver

# XXX would require Python dependency
#do-test:
#	(cd ${WRKSRC}/cosimulation/cver/test && ${PYTHONBIN} test_all.py)

.include "../../cad/gplcver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
