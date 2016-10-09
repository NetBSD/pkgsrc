# $NetBSD: Makefile,v 1.9 2016/10/09 03:15:57 kamil Exp $

.include "../../cad/py-MyHDL/Makefile.common"

PKGNAME=	${DISTNAME:S/myhdl/MyHDL-gplcver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GPL Cver cosimulation support for py-MyHDL

BUILD_DIRS+=	cosimulation/cver
MAKE_FILE=	Makefile.lnx
MAKE_FLAGS+=	INCS=-I${BUILDLINK_PREFIX.gplcver}/lib/gplcver/pli_incs/
MAKE_FLAGS+=	CC=${CC:Q}

INSTALLATION_DIRS+=	lib/gplcver

do-install:
	${INSTALL_DATA} ${WRKSRC}/cosimulation/cver/myhdl_vpi.so \
		${DESTDIR}${PREFIX}/lib/gplcver

.include "../../cad/gplcver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
