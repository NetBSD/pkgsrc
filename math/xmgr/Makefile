# $NetBSD: Makefile,v 1.15 2002/09/23 23:19:42 jlam Exp $
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

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_FORTRAN=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-acegr-home="${PREFIX}"

ALL_TARGET=		# empty
INSTALL_TARGET=		install

.include "../../devel/netcdf/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
