# $NetBSD: Makefile,v 1.1.1.1 1999/02/10 12:54:26 frueauf Exp $
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

BUILD_DEPENDS=	bison:../../devel/bison
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	fort77-1.14a:../../lang/fort77
DEPENDS+=	netcdf-3.4:../../devel/netcdf

USE_X11=	YES
USE_MOTIF=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-acegr-home=${PREFIX} \
	--enable-extra-incpath=${X11BASE}/include/X11:${LOCALBASE}/include \
	--enable-extra-ldpath=${LOCALBASE}/lib
CONFIGURE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"

ALL_TARGET=
INSTALL_TARGET=	install

.include "../../mk/bsd.pkg.mk"
