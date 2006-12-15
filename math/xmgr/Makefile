# $NetBSD: Makefile,v 1.30 2006/12/15 20:32:59 joerg Exp $

DISTNAME=		xmgr-4.1.2
PKGREVISION=		4
CATEGORIES=		math
MASTER_SITES=		ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/ \
			ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/old/ \
			ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/ \
			ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/old/ \
			ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/ \
			ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/old/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://plasma-gate.weizmann.ac.il/Xmgr/
COMMENT=		Powerful XY plotting tool for workstations or X-terminals using X

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_X11BASE=		YES
USE_LANGUAGES=		c fortran
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-acegr-home=${PREFIX:Q}

BUILD_TARGET=		# empty
INSTALL_TARGET=		install

REPLACE_PERL+=		auxiliary/fdf2fit
USE_TOOLS+=		perl:run

.include "../../devel/netcdf/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
