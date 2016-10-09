# $NetBSD: Makefile,v 1.10 2016/10/09 03:15:57 kamil Exp $

.include "../../cad/py-MyHDL/Makefile.common"

PKGNAME=	${DISTNAME:C/myhdl/MyHDL-iverilog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Icarus Verilog cosimulation support for py-MyHDL

BUILD_DIRS+=		cosimulation/icarus
INSTALLATION_DIRS+=	lib/ivl

do-install:
	${INSTALL_DATA} ${WRKSRC}/cosimulation/icarus/myhdl.vpi \
		${DESTDIR}${PREFIX}/lib/ivl

.include "../../cad/iverilog/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
