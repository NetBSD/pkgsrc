# $NetBSD: Makefile,v 1.3 2006/05/04 16:58:05 drochner Exp $
#

DISTNAME=	myhdl-0.5.1
PKGNAME=	MyHDL-iverilog-0.5.1
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Icarus Verilog cosimulation support for py-MyHDL

BUILD_DIRS+=	cosimulation/icarus

do-install:
	${INSTALL_DATA} ${WRKSRC}/cosimulation/icarus/myhdl.vpi \
		${PREFIX}/lib/ivl

.include "../../cad/verilog/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
