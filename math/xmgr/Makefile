# $NetBSD: Makefile,v 1.25 2005/12/12 21:36:55 joerg Exp $

DISTNAME=		xmgr-4.1.2
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/ \
			ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/old/ \
			ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/ \
			ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/old/ \
			ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/ \
			ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/old/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://plasma-gate.weizmann.ac.il/Xmgr/
COMMENT=		Powerful XY plotting tool for workstations or X-terminals using X

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_X11BASE=		YES
USE_LANGUAGES=		fortran
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-acegr-home=${PREFIX:Q}

BUILD_TARGET=		# empty
INSTALL_TARGET=		install

.include "../../devel/netcdf/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
