# $NetBSD: Makefile,v 1.14 2002/04/23 02:08:54 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1998/12/12 22:27:21 jseger Exp
#

DISTNAME=		xmgr-4.1.2
CATEGORIES=		math
MASTER_SITES=		ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/ \
			ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/old/ \
			ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/ \
			ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/old/ \
			ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/ \
			ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/old/

MAINTAINER=		packages@NetBSD.org
HOMEPAGE=		http://plasma-gate.weizmann.ac.il/Xmgr/
COMMENT=		Powerful XY plotting tool for workstations or X-terminals using X

BUILD_DEPENDS=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_FORTRAN=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-acegr-home="${PREFIX}"
CONFIGURE_ARGS+=	--enable-extra-incpath="${EXTRA_INCDIRS}"
CONFIGURE_ARGS+=	--enable-extra-ldpath="${BUILDLINK_DIR}/lib"

EXTRA_INCDIRS=		${BUILDLINK_DIR}/include/X11:${BUILDLINK_DIR}/include

ALL_TARGET=		# empty
INSTALL_TARGET=		install

.include "../../devel/netcdf/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
