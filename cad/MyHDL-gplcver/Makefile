# $NetBSD: Makefile,v 1.8 2015/01/04 02:51:44 mef Exp $
#

DISTNAME=	myhdl-0.8.1
PKGNAME=	${DISTNAME:S/myhdl/MyHDL-gplcver/}
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	GPL Cver cosimulation support for py-MyHDL
LICENSE=	gnu-gpl-v2

BUILD_DIRS+=	cosimulation/cver
MAKE_FILE=	makefile.lnx
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/cosimulation/cver/myhdl_vpi.so \
		${DESTDIR}${PREFIX}/lib/gplcver

# XXX would require Python dependency
#do-test:
#	(cd ${WRKSRC}/cosimulation/cver/test && ${PYTHONBIN} test_all.py)

.include "../../cad/gplcver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
