# $NetBSD: Makefile,v 1.6 2000/07/25 08:33:58 jlam Exp $
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

BUILD_DEPENDS=		bison:../../devel/bison
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		netcdf-3.4:../../devel/netcdf

USE_FORTRAN=		# defined
USE_X11=		# defined
USE_MOTIF=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-acegr-home="${PREFIX}"
CONFIGURE_ARGS+=	--enable-extra-incpath="${EXTRA_INCDIRS}"
CONFIGURE_ARGS+=	--enable-extra-ldpath="${LOCALBASE}/lib"

EVAL_PREFIX+=		XPMDIR=xpm
EXTRA_INCDIRS=		${XPMDIR}/include/X11:${LOCALBASE}/include

ALL_TARGET=		# empty
INSTALL_TARGET=		install

.include "../../mk/bsd.pkg.mk"
