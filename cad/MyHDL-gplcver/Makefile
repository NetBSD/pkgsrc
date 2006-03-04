# $NetBSD: Makefile,v 1.2 2006/03/04 21:29:01 jlam Exp $
#

DISTNAME=	myhdl-0.5
PKGNAME=	MyHDL-gplcver-0.5
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	GPL Cver cosimulation support for py-MyHDL

BUILD_DIRS+=	cosimulation/cver
MAKEFILE=	makefile.lnx

do-install:
	${INSTALL_DATA} ${WRKSRC}/cosimulation/cver/myhdl_vpi.so \
		${PREFIX}/lib/gplcver

.include "../../cad/gplcver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
