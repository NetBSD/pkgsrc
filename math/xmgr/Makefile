# $NetBSD: Makefile,v 1.5 1999/11/23 17:55:11 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.13 1998/12/12 22:27:21 jseger Exp
#

DISTNAME=	xmgr-4.1.2
CATEGORIES=	math
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/ \
		ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/old/ \
		ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/ \
		ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/old/ \
		ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/ \
		ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/old/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://plasma-gate.weizmann.ac.il/Xmgr/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	netcdf-3.4:../../devel/netcdf
BUILD_DEPENDS=	${LOCALBASE}/bin/bison:../../devel/bison

USE_FORTRAN=	YES
USE_X11=	YES
USE_MOTIF=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-acegr-home=${PREFIX} \
	--enable-extra-incpath=${X11BASE}/include/X11:${LOCALBASE}/include \
	--enable-extra-ldpath=${LOCALBASE}/lib

ALL_TARGET=
INSTALL_TARGET=	install

.include "../../mk/bsd.pkg.mk"
