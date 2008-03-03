# $NetBSD: Makefile,v 1.5 2008/03/03 01:50:26 jlam Exp $
#

DISTNAME=	myhdl-0.5.1
PKGNAME=	MyHDL-gplcver-0.5.1
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	GPL Cver cosimulation support for py-MyHDL

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS+=	cosimulation/cver
MAKE_FILE=	makefile.lnx

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/gplcver
	${INSTALL_DATA} ${WRKSRC}/cosimulation/cver/myhdl_vpi.so \
		${DESTDIR}${PREFIX}/lib/gplcver

.include "../../cad/gplcver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
