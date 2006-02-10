# $NetBSD: Makefile,v 1.1.1.1 2006/02/10 17:05:03 drochner Exp $
#

DISTNAME=	myhdl-0.5
PKGNAME=	MyHDL-iverilog-0.5
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Icarus Verilog cosimulation support for py-MyHDL

BUILD_DIRS+=	cosimulation/icarus

do-install:
	${INSTALL_DATA} ${WRKSRC}/cosimulation/icarus/myhdl.vpi \
		${PREFIX}/lib/ivl

.include "../../cad/verilog/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
